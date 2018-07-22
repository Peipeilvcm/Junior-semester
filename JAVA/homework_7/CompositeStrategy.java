import java.util.ArrayList;

//��ϲ��Ի��࣬�˿����Ž��̳���

public abstract class CompositeStrategy extends BasicStrategy{
	
	public static final int CompositeBestForCustom = 3;
	
	protected ArrayList<Integer> strategyNUMList;
	protected String values;
	
	public CompositeStrategy(String strategyName){
		strategyNum = ++strategyNumSequence;
		this.strategyName = strategyName;
		strategyNUMList = new ArrayList<Integer>();
		strategyNUMList.add(0);	//�����ۿۼ��뵽��ϲ�����
	}
	
	public CompositeStrategy(int strategyNum, String strategyName){
		this.strategyNum = strategyNum;
		this.strategyName = strategyName;
		strategyNUMList = new ArrayList<Integer>();
		strategyNUMList.add(0);	//�����ۿۼ��뵽��ϲ�����
	}
	
	public abstract double getSubTotal(SaleLineItem item);
	
	private boolean initStrategies(){
		String[] valueList = values.split("[|]");
		for(String s : valueList){
			int strategyNum = Integer.parseInt(s);
			IPricingStrategy strategy = Controller.getInstance().getStrategy(strategyNum);
			if(strategy == null){
				strategyNUMList.clear();
				return false;
			}
			strategyNUMList.add(strategyNum);
		}
		return true;
	}
	/*
	public boolean removeSimpleStrategy(IPricingStrategy strategy){
		return strategyNUMList.remove(strategy);
	}*/
	
	public String getStrategyValue(){
		return values;
	}
	
	public boolean setStrategyValue(String value){
		values = value;
		
		return initStrategies();
	}
	
	public String getStrategyTypeStr(){
    	return "����Ż�";
    }
	
	public int getStrategyType(){
		return CompositeBestForCustom;
	}
}
