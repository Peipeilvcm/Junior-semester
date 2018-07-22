
public class BookSpecification {
	
	public static final int NOT_EXIST = 0;				//此时书本不存在
	public static final int NOT_COMPUTER_TEACHING = 1;	//非教材计算机
	public static final int TEACHING = 2;				//教材类
	public static final int COMIC = 3;					//连环画
	public static final int HEALTH = 4;					//健康类
	public static final int OTHER = 5;					//其它
	
	private String isbn;
	private String title;
	private double price;
	private int type;
	
	//构造函数
	public BookSpecification() {
		this.type = NOT_EXIST;
	}
	public BookSpecification(String isbn,
		String title,double price, int type) {
		this.isbn = isbn;
		this.title = title;
		this.price = price;
		this.type = type;
	}
	
	public String getTypeName(){
		switch(type){
		case NOT_EXIST:
			return null;
		case NOT_COMPUTER_TEACHING:
			return "非教材类计算机图书";
		case TEACHING:
			return "教材类图书";
		case COMIC:
			return "连环画类图书";
		case HEALTH:
			return "养生类图书";
		default:
			return "其它";
		}
	}
	
	//get函数,set函数
	public String getIsbn() {
		return isbn;
	}
	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public int getType() {
		return type;
	}
	public void setType(int category) {
		this.type = category;
	}
}
