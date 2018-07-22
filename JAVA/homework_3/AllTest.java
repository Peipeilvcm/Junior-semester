/**
 * 作者：裴子祥
 * 班级：计科7班
 * 学号：2015211921
 * 时间：2017.12.11
 */

import java.util.ArrayList;
import java.util.Random;

public class AllTest{
    static public final int EMPLOYEE_NUM = 10;
    static public final int SALARY = 0;
    static public final int HOURLY = 1;
    static public final int COMMISION = 2;
    static public final int BASEPLUSCOMM = 3;

    static public void main(String[] args){
        Random rand = new Random();
        ArrayList<Employee> employeeList = new ArrayList<Employee>();

        for(int i = 0; i < EMPLOYEE_NUM; ++i){
            switch(rand.nextInt(4)){     //随机生成Employ与其信息
                case SALARY:            //随机生成Salary Employee
                    employeeList.add(
                        new SalaridEmployee(
                            "Lebron_"+i,
                            "James_"+i,
                            "000000000"+i,
                            rand.nextInt(4096)
                        )
                    );
                    break;
                case HOURLY:
                    employeeList.add(
                        new HourlyEmployee(
                            "Stephon_"+i,
                            "Curry_"+i,
                            "000000000"+i,
                            rand.nextInt(256),
                            rand.nextInt(64)
                        )
                    );
                    break;
                case COMMISION:
                    employeeList.add(
                        new CommisionEmployee(
                            "Kevin_"+i,
                            "Durant_"+i,
                            "000000000"+i,
                            rand.nextInt(32768),
                            rand.nextDouble()
                        )
                    );
                    break;
                case BASEPLUSCOMM:
                    employeeList.add(
                        new BasePlusCommisionEmployee(
                            "Kyrie_"+i,
                            "Irving_"+i,
                            "000000000" + i,
                            rand.nextInt(16384),
                            rand.nextDouble(),
                            rand.nextInt(4096)
                        )
                    );
                    break;
            }
        }//for,生成10个实例

        //print
        for(Employee employee : employeeList){
            System.out.println(employee.toString());
            System.out.println();
        }
    }
}