
public abstract class BasicStrategy implements IPricingStrategy{
    public static int strategyNumSequence = 0;

    protected int strategyNum;		//策略编号
    protected String strategyName;		//策略名称
    protected int bookType;

    public abstract double getSubTotal(SaleLineItem item);
    
    //设置策略名称
    public boolean setStrategyName(String name){
        strategyName = name;
        return true;
    }

    public String getStrategyName(){
        return strategyName;
    }

    public int getStrategyNum(){
        return strategyNum;
    }
    
    public boolean setBookType(int type){
		/*
		IPricingStrategy occupy = StrategyCatalog.getType();
    	if (occupy != null && this != occupy){
    		return false;
    	}*/
		bookType = type;
		return true;
	}
    
    public int getBookType(){
    	return bookType;
    }
    
    public abstract String getStrategyValue();
}
