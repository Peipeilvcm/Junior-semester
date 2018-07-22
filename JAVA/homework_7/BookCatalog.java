
import java.util.ArrayList;

//书本目录

public class BookCatalog {
	//单例模式
	private static BookCatalog instance = null;
	//所有书
	private ArrayList<BookSpecification> books;
	//观察者模式
	private ArrayList<Observer> observerList;		
	
	//构造函数
	private BookCatalog(){
		books = new ArrayList<BookSpecification>();
		observerList = new ArrayList<Observer>();
	}
	
	public static BookCatalog getInstance(){
		if(instance == null){
			instance = new BookCatalog();
		}
		return instance;
	}
	
	public boolean addBook(BookSpecification book){
		
		for(BookSpecification bookTemp : books){
			if(bookTemp.getIsbn().equals(book.getIsbn())){
				Controller.getInstance().messageBox("添加失败,已存在ISBN为"+book.getIsbn()+"的图书", "ERROR");
				return false;
			}
		}
		books.add(book);
		
		notifyObservers();
		return true;
	}
	
	public ArrayList<BookSpecification> getBooks(){
		return books;
	}
	
	public BookSpecification getBook(String isbn){
		for(BookSpecification book : books){
			if(book.getIsbn().equals(isbn)){
				return book;
			}
		}
		return null;
	}
	
	//根据'isbn'号删除书
	public boolean removeBook(String isbn){
		for(BookSpecification book : books){
			if(book.getIsbn().equals(isbn)){
				boolean ans = books.remove(book);
				notifyObservers();
				return ans;
			}
		}
		return false;
	}
	
	public void editBook(BookSpecification book){
		for(BookSpecification bookTemp : books){
			if(bookTemp.getIsbn().equals(book.getIsbn())){
				bookTemp.setPrice(book.getPrice());
				bookTemp.setTitle(book.getTitle());
				bookTemp.setType(book.getType());
				
				notifyObservers();
				Controller.getInstance().updateSale();
			}
		}
	}
	
	public void registerObserver(Observer observer){
		observerList.add(observer);
	}
	
	public boolean removeObserver(Observer observer){
		return observerList.remove(observer);
	}
	
	public void notifyObservers(){
		for (Observer observer : observerList)
			observer.update();
	}
}
