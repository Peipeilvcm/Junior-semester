
//²ßÂÔ¹¤³§singleton mode

public class PricingStrategyFactory {
	
	private static PricingStrategyFactory instance = null;
	private StrategyCatalog catalog;
	
	private PricingStrategyFactory(){
		catalog = StrategyCatalog.getInstance();
	}
	
	public static PricingStrategyFactory getInstance(){
		if(null == instance){
			instance = new PricingStrategyFactory();
		}
		return instance;
	}
	
	public IPricingStrategy getPricingStrategy(int bookType){
		return  catalog.getStrategy(bookType);
	}
	
	public void setCatalog(StrategyCatalog catalog){
		this.catalog = catalog;
	}
}
