
//����ģʽ

public class NoDiscountStrategy extends BasicStrategy{
	
	private static NoDiscountStrategy instance = null;
	
	private NoDiscountStrategy(){
		strategyName = "���κ��ۿ�";
		strategyNum = 0;			//���ۿ۱��Ϊ0
		bookType = 0;				//���κ���
	}
	
	public static NoDiscountStrategy getInstance(){
        if (instance == null)
            instance = new NoDiscountStrategy();
        return instance;
    }
	
	public String getStrategyTypeStr(){
    	return "���Ż�";
    }
	
	@Override
	public double getSubTotal(SaleLineItem item){
		return item.getCopies()*item.getProdSpec().getPrice();
	}

	@Override
	public boolean setStrategyValue(String value) {
		// TODO Auto-generated method stub
		return false;
	}

	public String getStrategyValue() {
		// TODO Auto-generated method stub
		return "���κ��ۿ�";
	}

	@Override
	public int getStrategyType() {
		// TODO Auto-generated method stub
		return 0;
	}
	
}
