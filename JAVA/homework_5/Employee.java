
public abstract class Employee {
	private String firstName;
	private String lastName;
	private String socialSecurityNumber;

	public Employee(){
		firstName = null;
		lastName = null;
		socialSecurityNumber = null;
	}
	public Employee(String fN, String lN, String sSN){
		firstName = fN;
		lastName = lN;
		socialSecurityNumber = sSN;
	}

	public final void setFirstName(String fN){			//final修饰，不能被子类覆盖
		firstName = fN;
	}
	public final void setLastName(String lN){
		lastName = lN;
	}
	public final String getFirstName(){
		return firstName;
	}
	public final String getLastName(){
		return lastName;
	}
	public final String getSocialSecurityNumber(){
		return socialSecurityNumber;
	}

	public abstract int earning();//抽象类方法，用于计算员工的月工资

	@Override
	public String toString(){
		return 
			"Employee" + 
			"\nFirst Name: " + getFirstName() +
			"\nLast Name: " + getLastName() +
			"\nSocial Security Number: " + getSocialSecurityNumber();
	}
}
