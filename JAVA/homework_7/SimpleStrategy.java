
//简单策略,百分比策略和绝对值策略在此技术上

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
    		return "百分比优惠";
    	case FLAT_RATE:
    		return "绝对值优惠";
    	default:
    		return "";
    	}
    }
	
}
