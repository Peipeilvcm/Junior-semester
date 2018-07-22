import java.util.HashMap;
import java.util.Random;

public class Factory{
    static private final int EMPLOYEE_NUM = 10;
    static private final int SALARY = 0;
    static private final int HOURLY = 1;
    static private final int COMMISION = 2;
    static private final int BASEPLUSCOMM = 3;
    

    private HashMap<String ,Employee> employees;

    public Factory(){
        employees = new HashMap<String, Employee>();
    }

    public void initEmployees(){
        Random rand = new Random();
        for(int i = 0; i < EMPLOYEE_NUM; ++i){
            
            //自动生成 SocialSecurityNumber 第一位为i,后三位随机数
            String SSN = i + "" + rand.nextInt(9) +
                             "" + rand.nextInt(9) +
                             "" + rand.nextInt(9); 
            
            int type = rand.nextInt(4);
            switch(type){
                case SALARY:
                    this.addEmployee(
                        new SalaridEmployee(
                            "Lebron_"+i,
                            "James_"+i,
                            SSN,
                            rand.nextInt(4096)
                        )
                    );
                    break;
                case HOURLY:
                    this.addEmployee(
                        new HourlyEmployee(
                            "Stephon_"+i,
                            "Curry_"+i,
                            SSN,
                            rand.nextInt(256),
                            rand.nextInt(64)
                        )
                    );
                    break;
                case COMMISION:
                    this.addEmployee(
                        new CommisionEmployee(
                            "Kevin_"+i,
                            "Durant_"+i,
                            SSN,
                            rand.nextInt(32768),
                            rand.nextDouble()
                        )
                    );
                    break;
                case BASEPLUSCOMM:
                    this.addEmployee(
                        new BasePlusCommisionEmployee(
                            "Kyrie_"+i,
                            "Irving_"+i,
                            SSN,
                            rand.nextInt(16384),
                            rand.nextDouble(),
                            rand.nextInt(4096)
                        )
                    );
                    break;
            }
        }
    }

    public Employee getEmployee(String empSecNum){
        return employees.get(empSecNum);
    }

    public Employee deleteEmployee(String empSecNum){
        return employees.remove(empSecNum);
    }

    public Employee addEmployee(Employee stu){
        if(employees.get(stu.getSocialSecurityNumber()) == null){
            employees.put(stu.getSocialSecurityNumber(), stu);
            return stu;
        }
        else{  //员工已经存在
            return null;
        }
    }

    public Employee updateEmployee(String empSecNum, Employee stu){
        if(employees.get(empSecNum) != null){
            employees.put(empSecNum, stu);
            return stu;
        }
        else{
            return null;
        }
    }

    public void printEmployees(){
        for(Employee stu : employees.values()){
            System.out.println(stu.toString());
            System.out.println();
        }
    }
}
