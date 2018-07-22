import javax.swing.JOptionPane;

//������̨

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
		sale.updateStrategy(strateNum);		//�������
		updateSale();		//�۲��߸���
		//return strategy;
	}
	
	public void editStrategy(int strategyNum, IPricingStrategy strategy){
		StrategyCatalog.getInstance().editStrategy(new Integer(strategyNum), strategy);
		sale.updateStrategy(strategyNum);		//�������
		updateSale();		//�۲��߸���
		
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
			//ɾ���ɹ�
			sale.clearBook(book);
			return true;
		}
		return false;
	}
	
	//���һ����¼
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
	
	//�Ƴ�һ����¼
	public boolean removeSaleItem(SaleLineItem item){
		return sale.removeItem(item);
	}
	
	public boolean removeSaleItem(int saleLineNum){
		return sale.removeItem(saleLineNum);
	}
	
	//�༭ͼ��
	public void editBook(BookSpecification book){
		BookCatalog.getInstance().editBook(book);	//�޸�ͼ����Ϣ
	}
	
	//����ͼ��۲���
	public void updateBook(){
		BookCatalog.getInstance().notifyObservers();
	}
	
	
	//���²��Թ۲���
	public void updateStrategy(){					//���²������UI
		StrategyCatalog.getInstance().notifyObserver();
	}
	
	//���¹����嵥
	public void updateSale(){
		//sale.updateStrategy();
		sale.notifyObservers();
	}
	
	//��չ��ﳵ
	public void clearShopCart(){
		sale.clear();
	}
	
	public void messageBox(String mess, String title){
		JOptionPane.showMessageDialog(
			null, mess,  title,  JOptionPane.PLAIN_MESSAGE); 
	}
	
	//��ʼ����Ϣ����һЩͼ��Ͳ�����Ϣд��
	public void initInfo(){
		
		//ͼ��Ŀ¼���ͼ��
		BookSpecification UMLBOOK = new BookSpecification(
			"978-7-302-2", "UML��ģʽӦ��", 18, BookSpecification.TEACHING);
		BookCatalog.getInstance().addBook(UMLBOOK);
		
		BookSpecification JAVABOOK = new BookSpecification(
			"978-7-312-3", "Java��ģʽ", 34, BookSpecification.NOT_COMPUTER_TEACHING);
		BookCatalog.getInstance().addBook(JAVABOOK);
		
		BookSpecification HEADFIRST = new BookSpecification(
			"986-6-302-1", "Head First���ģʽ", 58, BookSpecification.NOT_COMPUTER_TEACHING);
		BookCatalog.getInstance().addBook(HEADFIRST);
		
		BookSpecification ALICEBOOK = new BookSpecification(
			"958-1-302-2", "����˿���ռ�", 30, BookSpecification.COMIC);
		BookCatalog.getInstance().addBook(ALICEBOOK);
		
		BookSpecification COOKBOOK = new BookSpecification(
			"900-7-392-2", "������ȫ", 20, BookSpecification.HEALTH);
		BookCatalog.getInstance().addBook(COOKBOOK);
		
		//����Ŀ¼��ʼ����Ϣ
		IPricingStrategy discount001 = new FlatRateStrategy("����ֵ�Żݲ���1", 1.0);
        discount001.setBookType(BookSpecification.TEACHING);// ����ͼ������ 2
        StrategyCatalog.getInstance().addStrategy(discount001);
        IPricingStrategy discount002 = new PrecentageStrategy("�ٷֱ��ۿ۲���1", 7);
        discount002.setBookType(BookSpecification.COMIC);// ����ͼ������ 3
        StrategyCatalog.getInstance().addStrategy(discount002);
        IPricingStrategy discount003 = new PrecentageStrategy("�ٷֱ��ۿ۲���2", 3);
        discount003.setBookType(BookSpecification.NOT_COMPUTER_TEACHING);// ����ͼ������ 1
        StrategyCatalog.getInstance().addStrategy(discount003);
        IPricingStrategy discount004 = new CompositeBestForCustomer("�˿����Ų���1");
        discount004.setBookType(BookSpecification.HEALTH);// ����ͼ������ 4���� Discount001 �� Discount003 ���
        discount004.setStrategyValue("1|3");
        StrategyCatalog.getInstance().addStrategy(discount004);
	
        //��ʼ��������Ϣ
        sale.addItem(new SaleLineItem(2, UMLBOOK));// ���� 2 ����UML ��ģʽӦ�á�
        sale.addItem(new SaleLineItem(2, JAVABOOK));// ���� 2 ����Jave ��ģʽ��
        sale.addItem(new SaleLineItem(1, HEADFIRST));// ���� 1 ����HeadFirst ���ģʽ��
        sale.addItem(new SaleLineItem(3, ALICEBOOK));// ���� 3 ��������˿���ռǡ�
        sale.addItem(new SaleLineItem(1, COOKBOOK));// ���� 1 ����������ȫ��
	}
	
	public String bookTypeToStr(int bookType){
		switch(bookType){
		case 0:
			return null;
		case 1:
			return "�ǽ̲�������ͼ��";
		case 2:
			return "�̲���ͼ��";
		case 3:
			return "��������ͼ��";
		case 4:
			return "������ͼ��";
		default:
			return "����";
		}
	}
	
}
