
public class FlatRateStrategy extends SimpleStrategy{
	
	private double discountPerBook;
	
	public FlatRateStrategy(int strategyNum , String strategyName, double discountPerBook){
		this.strategyName = strategyName;
		this.strategyNum = strategyNum;
		strategyType = FLAT_RATE;
		this.discountPerBook = discountPerBook;
	}
	
	public FlatRateStrategy(String strategyName, double discountPerBook){
		this.strategyName = strategyName;
		strategyNum = ++strategyNumSequence;
		strategyType = FLAT_RATE;
		this.discountPerBook = discountPerBook;
	}
	
	@Override
	public double getSubTotal(SaleLineItem item){
		return item.getCopies()*(item.getProdSpec().getPrice()-discountPerBook);
	}
	
	public String getStrategyValue(){
		return String.format("%.2f", discountPerBook);
	}

	@Override
	public boolean setStrategyValue(String value) {
		// TODO Auto-generated method stub
		double valueTemp;
		try{
			valueTemp = Float.parseFloat(value);
		}
		catch(Exception e){
			return false;
		}
		discountPerBook = valueTemp;
		return true;
	}
	
}
