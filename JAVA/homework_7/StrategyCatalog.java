
import java.util.ArrayList;
import java.util.HashMap;

//策略目录
public class StrategyCatalog {

	//策略编号与策略一一映射
	private HashMap<Integer, IPricingStrategy> strategies;
	private ArrayList<Observer> observers;
	private static StrategyCatalog instance;
	
	private StrategyCatalog(){
		strategies = new HashMap<>();
		strategies.put(0, NoDiscountStrategy.getInstance());//将无折扣策略添加至初始策略目录中
		observers = new ArrayList<Observer>();
	}
	public static StrategyCatalog getInstance(){		//单例模式
		if(null == instance){
			instance = new StrategyCatalog();
		}
		return instance;
	}
	
	//观察者操作
	public void registerObserver(Observer obs){
		observers.add(obs);
	}
	
	public boolean removeObserver(Observer obs){
		return observers.remove(obs);
	}
	
	public void notifyObserver(){
		for(Observer obs : observers){
			obs.update();
		}
	}
	
	public boolean isOccupied(int bookType){
		if(bookType == 0){
			return false;
		}
		for(IPricingStrategy strategy : strategies.values()){
			if(strategy.getBookType() == bookType){
				return true;			//该类图书已经对应了折扣策略
			}
		}
		return false;
	}
	
	/*
	public HashMap<Integer, IPricingStrategy> getStrategies(){
		return strategies;
	}*/
	
	
	
	//找查策略,按书类查找
	public IPricingStrategy getStrategy(int bookType){
		
		for(IPricingStrategy strategy : strategies.values()){
			if(strategy.getBookType() == bookType){
				return strategy;
			}
		}
		return NoDiscountStrategy.getInstance();
	}
	//策略编号找到策略
	public IPricingStrategy getStrategyOnNum(int num){
		return strategies.get(num);
	}
	
	//添加策略
	public void addStrategy(IPricingStrategy strategy){
		strategies.put(strategy.getStrategyNum(), strategy);
		notifyObserver();
	}
	
	//移除策略
	public IPricingStrategy removeStrategy(IPricingStrategy strategy){
		IPricingStrategy res = strategies.remove(strategy.getStrategyNum());
		if(res == null){
			return null;
		}
		notifyObserver();
		return res;
	}
	public void removeStrategy(Integer strateNum){
		strategies.remove(strateNum);
		notifyObserver();
		//return res;
	}
	
	//编辑策略
	public void editStrategy(Integer strategyNum, IPricingStrategy strategy){
		strategies.put(strategyNum, strategy);
		notifyObserver();
	}
	
	
	//获得所有策略列表
	public ArrayList<IPricingStrategy> getStrategies(){
		ArrayList<IPricingStrategy> strategyList = new ArrayList<IPricingStrategy>();
		for(IPricingStrategy strategy : strategies.values()){
			strategyList.add(strategy);
		} 
		return strategyList;
	}
	
	
	
	
	
}
