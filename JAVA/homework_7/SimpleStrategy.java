
//�򵥲���,�ٷֱȲ��Ժ;���ֵ�����ڴ˼�����

public abstract class SimpleStrategy extends BasicStrategy{
	
	public static final int PERCENTAGE = 1;
	public static final int FLAT_RATE = 2;
	
	protected int strategyType;

    public int getStrategyType(){
        return strategyType;
    }
    
    public String getStrategyTypeStr(){
    	switch(strategyType){
    	case PERCENTAGE:
    		return "�ٷֱ��Ż�";
    	case FLAT_RATE:
    		return "����ֵ�Ż�";
    	default:
    		return "";
    	}
    }
	
}
