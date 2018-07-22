
public class SaleLineItem {
	
	private static int numSequence = 0;		//��¼��ǰ���Ѽ�¼���
	
	private int saleItemNum;				//���Ѽ�¼���,ÿ����һ��
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
	
	public void updateStrategy(){//���²���
		strategy = PricingStrategyFactory.getInstance().getPricingStrategy(prodSpec.getType());
	
	}
	
	public void setCopies(int copies){
		this.copies = copies;
	}
}
