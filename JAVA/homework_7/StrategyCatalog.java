
import java.util.ArrayList;
import java.util.HashMap;

//����Ŀ¼
public class StrategyCatalog {

	//���Ա�������һһӳ��
	private HashMap<Integer, IPricingStrategy> strategies;
	private ArrayList<Observer> observers;
	private static StrategyCatalog instance;
	
	private StrategyCatalog(){
		strategies = new HashMap<>();
		strategies.put(0, NoDiscountStrategy.getInstance());//�����ۿ۲����������ʼ����Ŀ¼��
		observers = new ArrayList<Observer>();
	}
	public static StrategyCatalog getInstance(){		//����ģʽ
		if(null == instance){
			instance = new StrategyCatalog();
		}
		return instance;
	}
	
	//�۲��߲���
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
				return true;			//����ͼ���Ѿ���Ӧ���ۿ۲���
			}
		}
		return false;
	}
	
	/*
	public HashMap<Integer, IPricingStrategy> getStrategies(){
		return strategies;
	}*/
	
	
	
	//�Ҳ����,���������
	public IPricingStrategy getStrategy(int bookType){
		
		for(IPricingStrategy strategy : strategies.values()){
			if(strategy.getBookType() == bookType){
				return strategy;
			}
		}
		return NoDiscountStrategy.getInstance();
	}
	//���Ա���ҵ�����
	public IPricingStrategy getStrategyOnNum(int num){
		return strategies.get(num);
	}
	
	//��Ӳ���
	public void addStrategy(IPricingStrategy strategy){
		strategies.put(strategy.getStrategyNum(), strategy);
		notifyObserver();
	}
	
	//�Ƴ�����
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
	
	//�༭����
	public void editStrategy(Integer strategyNum, IPricingStrategy strategy){
		strategies.put(strategyNum, strategy);
		notifyObserver();
	}
	
	
	//������в����б�
	public ArrayList<IPricingStrategy> getStrategies(){
		ArrayList<IPricingStrategy> strategyList = new ArrayList<IPricingStrategy>();
		for(IPricingStrategy strategy : strategies.values()){
			strategyList.add(strategy);
		} 
		return strategyList;
	}
	
	
	
	
	
}
