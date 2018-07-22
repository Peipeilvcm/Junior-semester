
public interface IPricingStrategy {
	
	public double getSubTotal(SaleLineItem item);//总值
	
	public int getStrategyType();
	public int getStrategyNum();	//定价策略编号
    public String getStrategyName();		//策略名称
	public String getStrategyValue();		//策略优惠关键值
	public String getStrategyTypeStr();		//策略类型
	public int getBookType();
	public boolean setStrategyName(String name);
	public boolean setStrategyValue(String value);	//设置策略优惠值
	public boolean setBookType(int booktype);
	//public void setStrategyType(String strategyType);
	
	//public String getDescription();
	/*
	public String getIndex();
	public String getName();
	
	public String getDescription();
	*/
	
	
	
}
