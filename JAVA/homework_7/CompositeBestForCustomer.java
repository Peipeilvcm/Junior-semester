

//ѡȡ��ϲ��԰��������м򵥲��������ŵ�һ�֡�

public class CompositeBestForCustomer extends CompositeStrategy {
	
	//private String values;
	
	public CompositeBestForCustomer(int strategyNum, String strategyName){
        super(strategyNum, strategyName);
    }
	
	public CompositeBestForCustomer(String strategyName){
        super(strategyName);
    }

    public double getSubTotal(SaleLineItem item){
        double mini = NoDiscountStrategy.getInstance().getSubTotal(item);
        for (Integer strategyNum: strategyNUMList){
        	IPricingStrategy strategy = Controller.getInstance().getStrategy(strategyNum);
        	if(strategy == null){
        		//strategyNUMList.remove(strategyNum);
        		
        		continue;
        	}

            double nowCost = strategy.getSubTotal(item);
            if(nowCost<mini){
            	mini = nowCost;
            }
        }

        return mini;
    }

}
