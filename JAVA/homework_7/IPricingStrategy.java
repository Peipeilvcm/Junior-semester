
public interface IPricingStrategy {
	
	public double getSubTotal(SaleLineItem item);//��ֵ
	
	public int getStrategyType();
	public int getStrategyNum();	//���۲��Ա��
    public String getStrategyName();		//��������
	public String getStrategyValue();		//�����Żݹؼ�ֵ
	public String getStrategyTypeStr();		//��������
	public int getBookType();
	public boolean setStrategyName(String name);
	public boolean setStrategyValue(String value);	//���ò����Ż�ֵ
	public boolean setBookType(int booktype);
	//public void setStrategyType(String strategyType);
	
	//public String getDescription();
	/*
	public String getIndex();
	public String getName();
	
	public String getDescription();
	*/
	
	
	
}
