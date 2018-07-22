
public class PrecentageStrategy extends SimpleStrategy{
	
	private int discountPercentage;
	
	public PrecentageStrategy(String strategyName, int discountPercentage){
		this.strategyName = strategyName;
		strategyNum = ++strategyNumSequence;
		strategyType = PERCENTAGE;
		this.discountPercentage = discountPercentage;
	}
	
	public PrecentageStrategy(int strategyNum, String strategyName, int discountPercentage){
		this.strategyName = strategyName;
		this.strategyNum = strategyNum;
		strategyType = PERCENTAGE;
		this.discountPercentage = discountPercentage;
	}
	
	@Override
	public double getSubTotal(SaleLineItem item){
		return item.getCopies()*item.getProdSpec().getPrice()*(100-discountPercentage)/100.0;
	}
	
	@Override
	public String getStrategyValue(){
		return discountPercentage + "";
	}

	@Override
	public boolean setStrategyValue(String value) {
		// TODO Auto-generated method stub
		int valueTemp;
		try{
			valueTemp = Integer.parseInt(value);
		}
		catch(Exception e){
			return false;
		}
		discountPercentage = valueTemp;
		return true;
	}
}
