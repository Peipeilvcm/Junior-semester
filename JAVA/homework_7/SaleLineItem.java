
public class SaleLineItem {
	
	private static int numSequence = 0;		//记录当前消费记录编号
	
	private int saleItemNum;				//消费记录编号,每增加一个
	private int copies;
	private BookSpecification prodSpec;
	private IPricingStrategy strategy;
	
	public SaleLineItem(int copies, BookSpecification proSpec){
		saleItemNum = ++numSequence;
		this.copies = copies;
		this.prodSpec = proSpec;
		this.strategy = StrategyCatalog.getInstance().getStrategy(proSpec.getType());
	}
	
	public int getSaleItemNum(){
		return saleItemNum;
	}
	
	public double getSubTotal(){
		return strategy.getSubTotal(this);
	}
	
	public int getCopies() {
		return copies;
	}

	public BookSpecification getProdSpec() {
		return prodSpec;
	}
	
	public IPricingStrategy getStrategy(){
		return strategy;
	}
	
	public void updateStrategy(){//更新策略
		strategy = PricingStrategyFactory.getInstance().getPricingStrategy(prodSpec.getType());
	
	}
	
	public void setCopies(int copies){
		this.copies = copies;
	}
}
