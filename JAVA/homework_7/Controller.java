import javax.swing.JOptionPane;

//主控制台

public class Controller {
	
	private Sale sale;
	private static Controller instance = null;
	private Controller(){
		sale = new Sale();
	}
	
	public static Controller getInstance(){
		if(instance == null){
			instance = new Controller();
		}
		return instance;
	}
	
	public Sale getSale(){
		return sale;
	}
	
	public IPricingStrategy getStrategy(int strategyNum){
		return StrategyCatalog.getInstance().getStrategyOnNum(strategyNum);
	}
	
	public void addStrategy(IPricingStrategy strategy){
		StrategyCatalog.getInstance().addStrategy(strategy);
	}
	
	public void removeStrategy(int strateNum){
		StrategyCatalog.getInstance().removeStrategy(strateNum);
		sale.updateStrategy(strateNum);		//本身更新
		updateSale();		//观察者更新
		//return strategy;
	}
	
	public void editStrategy(int strategyNum, IPricingStrategy strategy){
		StrategyCatalog.getInstance().editStrategy(new Integer(strategyNum), strategy);
		sale.updateStrategy(strategyNum);		//本身更新
		updateSale();		//观察者更新
		
	}
	
	public BookSpecification getBook(String isbn){
		return BookCatalog.getInstance().getBook(isbn);
	}
	
	public boolean addBook(BookSpecification book){
		return BookCatalog.getInstance().addBook(book);
	}
	
	public boolean removeBook(String isbn){
		BookSpecification book = BookCatalog.getInstance().getBook(isbn);
		if(book == null){
			return false;
		}
		if(BookCatalog.getInstance().removeBook(isbn)){
			//删除成功
			sale.clearBook(book);
			return true;
		}
		return false;
	}
	
	//添加一条记录
	public boolean addSaleItem(String isbn, int copies){
		BookSpecification book = getBook(isbn);
		if(book == null){
			return false;
		}
		SaleLineItem item = new SaleLineItem(copies, book);
		sale.addItem(item);
		return true;
	}
	
	public void addSaleItem(SaleLineItem item){
		sale.addItem(item);
	}
	
	//移除一条记录
	public boolean removeSaleItem(SaleLineItem item){
		return sale.removeItem(item);
	}
	
	public boolean removeSaleItem(int saleLineNum){
		return sale.removeItem(saleLineNum);
	}
	
	//编辑图书
	public void editBook(BookSpecification book){
		BookCatalog.getInstance().editBook(book);	//修改图书信息
	}
	
	//更新图书观察者
	public void updateBook(){
		BookCatalog.getInstance().notifyObservers();
	}
	
	
	//更新策略观察者
	public void updateStrategy(){					//更新策略相关UI
		StrategyCatalog.getInstance().notifyObserver();
	}
	
	//更新购物清单
	public void updateSale(){
		//sale.updateStrategy();
		sale.notifyObservers();
	}
	
	//清空购物车
	public void clearShopCart(){
		sale.clear();
	}
	
	public void messageBox(String mess, String title){
		JOptionPane.showMessageDialog(
			null, mess,  title,  JOptionPane.PLAIN_MESSAGE); 
	}
	
	//初始化信息，将一些图书和策略信息写入
	public void initInfo(){
		
		//图书目录添加图书
		BookSpecification UMLBOOK = new BookSpecification(
			"978-7-302-2", "UML与模式应用", 18, BookSpecification.TEACHING);
		BookCatalog.getInstance().addBook(UMLBOOK);
		
		BookSpecification JAVABOOK = new BookSpecification(
			"978-7-312-3", "Java与模式", 34, BookSpecification.NOT_COMPUTER_TEACHING);
		BookCatalog.getInstance().addBook(JAVABOOK);
		
		BookSpecification HEADFIRST = new BookSpecification(
			"986-6-302-1", "Head First设计模式", 58, BookSpecification.NOT_COMPUTER_TEACHING);
		BookCatalog.getInstance().addBook(HEADFIRST);
		
		BookSpecification ALICEBOOK = new BookSpecification(
			"958-1-302-2", "爱丽丝历险记", 30, BookSpecification.COMIC);
		BookCatalog.getInstance().addBook(ALICEBOOK);
		
		BookSpecification COOKBOOK = new BookSpecification(
			"900-7-392-2", "煲汤大全", 20, BookSpecification.HEALTH);
		BookCatalog.getInstance().addBook(COOKBOOK);
		
		//策略目录初始化信息
		IPricingStrategy discount001 = new FlatRateStrategy("绝对值优惠策略1", 1.0);
        discount001.setBookType(BookSpecification.TEACHING);// 适用图书类型 2
        StrategyCatalog.getInstance().addStrategy(discount001);
        IPricingStrategy discount002 = new PrecentageStrategy("百分比折扣策略1", 7);
        discount002.setBookType(BookSpecification.COMIC);// 适用图书类型 3
        StrategyCatalog.getInstance().addStrategy(discount002);
        IPricingStrategy discount003 = new PrecentageStrategy("百分比折扣策略2", 3);
        discount003.setBookType(BookSpecification.NOT_COMPUTER_TEACHING);// 适用图书类型 1
        StrategyCatalog.getInstance().addStrategy(discount003);
        IPricingStrategy discount004 = new CompositeBestForCustomer("顾客最优策略1");
        discount004.setBookType(BookSpecification.HEALTH);// 适用图书类型 4，由 Discount001 和 Discount003 组成
        discount004.setStrategyValue("1|3");
        StrategyCatalog.getInstance().addStrategy(discount004);
	
        //初始化购买信息
        sale.addItem(new SaleLineItem(2, UMLBOOK));// 购买 2 本《UML 与模式应用》
        sale.addItem(new SaleLineItem(2, JAVABOOK));// 购买 2 本《Jave 与模式》
        sale.addItem(new SaleLineItem(1, HEADFIRST));// 购买 1 本《HeadFirst 设计模式》
        sale.addItem(new SaleLineItem(3, ALICEBOOK));// 购买 3 本《爱丽丝历险记》
        sale.addItem(new SaleLineItem(1, COOKBOOK));// 购买 1 本《煲汤大全》
	}
	
	public String bookTypeToStr(int bookType){
		switch(bookType){
		case 0:
			return null;
		case 1:
			return "非教材类计算机图书";
		case 2:
			return "教材类图书";
		case 3:
			return "连环画类图书";
		case 4:
			return "养生类图书";
		default:
			return "其它";
		}
	}
	
}
