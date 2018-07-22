
public class BookSpecification {
	
	public static final int NOT_EXIST = 0;				//��ʱ�鱾������
	public static final int NOT_COMPUTER_TEACHING = 1;	//�ǽ̲ļ����
	public static final int TEACHING = 2;				//�̲���
	public static final int COMIC = 3;					//������
	public static final int HEALTH = 4;					//������
	public static final int OTHER = 5;					//����
	
	private String isbn;
	private String title;
	private double price;
	private int type;
	
	//���캯��
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
			return "�ǽ̲�������ͼ��";
		case TEACHING:
			return "�̲���ͼ��";
		case COMIC:
			return "��������ͼ��";
		case HEALTH:
			return "������ͼ��";
		default:
			return "����";
		}
	}
	
	//get����,set����
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
