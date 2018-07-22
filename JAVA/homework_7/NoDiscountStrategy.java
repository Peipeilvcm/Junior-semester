
//单例模式

public class NoDiscountStrategy extends BasicStrategy{
	
	private static NoDiscountStrategy instance = null;
	
	private NoDiscountStrategy(){
		strategyName = "无任何折扣";
		strategyNum = 0;			//无折扣编号为0
		bookType = 0;				//对任何书
	}
	
	public static NoDiscountStrategy getInstance(){
        if (instance == null)
            instance = new NoDiscountStrategy();
        return instance;
    }
	
	public String getStrategyTypeStr(){
    	return "无优惠";
    }
	
	@Override
	public double getSubTotal(SaleLineItem item){
		return item.getCopies()*item.getProdSpec().getPrice();
	}

	@Override
	public boolean setStrategyValue(String value) {
		// TODO Auto-generated method stub
		return false;
	}

	public String getStrategyValue() {
		// TODO Auto-generated method stub
		return "无任何折扣";
	}

	@Override
	public int getStrategyType() {
		// TODO Auto-generated method stub
		return 0;
	}
	
}
