import java.util.ArrayList;

public class Sale implements Subject{
	private ArrayList<SaleLineItem> items;
	private ArrayList<Observer> observers;		//观察者
	
	public double getTotal(){				//获得总价钱
		double res = 0.0;
		for(SaleLineItem item : items){
			res += item.getSubTotal();
		}
		return res;
	}
	
	public Sale(){
		items = new ArrayList<SaleLineItem>();
		observers = new ArrayList<Observer>();
	}
	
	public ArrayList<SaleLineItem> getItems(){
		return items;
	}
	
	public void addItem(SaleLineItem item){
		boolean isExit = false;
		for(SaleLineItem itemTemp : items){//若已经有，则改变数量
			if(itemTemp.getProdSpec().getIsbn().equals(item.getProdSpec().getIsbn())){
				itemTemp.setCopies(itemTemp.getCopies()+item.getCopies());
				isExit = true;
				break;
			}
		}
		if(isExit == false){
			items.add(item);
		}
		notifyObservers();
	}
	
	//删除一条记录
	public boolean removeItem(SaleLineItem item){
		for(SaleLineItem itempTemp : items){
			if(itempTemp.getSaleItemNum() == item.getSaleItemNum()){
				boolean res = items.remove(itempTemp);
				if(res == true){
					notifyObservers();
				}
				return res;
			}
		}
		return false;
	}
	
	public boolean removeItem(int saleLineNum){
		for(SaleLineItem itempTemp : items){
			if(itempTemp.getSaleItemNum() == saleLineNum){
				boolean res = items.remove(itempTemp);
				if(res == true){
					notifyObservers();
				}
				return res;
			}
		}
		return false;
	}
	
	public void clear(){		//清空一次购物中图书信息
		items.clear();
		notifyObservers();
	}
	
	public void clearBook(BookSpecification book){
		for(SaleLineItem item : items){
			if(item.getProdSpec().getIsbn().equals(book.getIsbn())){
				items.remove(item);
				break;
			}
		}
		notifyObservers();
	}
	
	public void updateStrategy(int strategyNum){
		for(SaleLineItem item : items){
			if(item.getStrategy().getStrategyNum() == strategyNum){
				item.updateStrategy();
			}
		}
		
	}
	public void updateStrategy(){
		for(SaleLineItem item : items){
			item.updateStrategy();
		}
	}
	
	//观察者接口
	@Override
	public void registerObserver(Observer observer){
		observers.add(observer);
	}
	@Override
	public void removeObserver(Observer observer){
		observers.remove(observer);
	}
	@Override
	public void notifyObservers(){
		for (Observer observer : observers)
			observer.update();
	}
	
}
