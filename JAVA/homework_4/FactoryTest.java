import java.util.Scanner;

public class FactoryTest {
	
	private static Factory factoryTest;
	
	private static Scanner inScan;
	
	private static void printMenu(){
        System.out.println(
            "--------------------------------MENU--------------------------------\n" +
            "输入数字1~6,选择对应一项操作\n" +
            "1. 输入要查询的员工社会保险号,输出员工信息\n" +
            "2. 对于已经存在于员工列表中的一个员工,输入更新信息来更新列表中的员工对象\n" +
            "3. 对于已经存在于员工列表中的一个员工,将其从HashMap中删除\n" +
            "4. 打印全部员工的信息\n" +
            "5. 添加新员工\n" +
            "6. 退出程序\n"
        );
    }
	
	private static void searchCommand(){
        //Scanner inScan = new Scanner(System.in);
        System.out.print("输入要查询的员工社会保险号:");
        
        Employee stu = null;
        stu = factoryTest.getEmployee(inScan.next().trim());

        if (stu != null) {
            System.out.println("该员工信息如下:");
            System.out.println(stu.toString());
        } 
        else {
            System.out.println("查无此员工");
        }
        //inScan.close();
    }
	
	private static void updateCommand() throws Exception{
		
		System.out.print ("输入需要更新的员工社会保险号：");
		String SSN = inScan.next ().trim ();
		
		if(factoryTest.getEmployee(SSN) == null){
			System.out.println ("查无此员工");
			return;
		}
		
		System.out.print ("输入员工FirstNmae：");
		String firstName = inScan.next ().trim ();

		System.out.print ("输入员工LastName：");
		String lastName = inScan.next ().trim ();
		
		System.out.println("请输入员工类别：\n" +
						  "0 - SalaridEmployee\n" +
						  "1 - HourlyEmployee\n" +
						  "2 - CommisionEmployee\n" +
						  "3 - BasePlusCommisionEmployee");
		
		int type = inScan.nextInt();

		Employee stu;

		switch (type){
			case 0:{
				System.out.print("输入weeklySalary：");
				int weeklySalary = inScan.nextInt();
	
				stu = factoryTest.updateEmployee(SSN,
					new SalaridEmployee(
						firstName, lastName, SSN, weeklySalary));
				break;
			}
			case 1:{
				System.out.print ("输入wage：");
				int wage = inScan.nextInt();
	
				System.out.print ("输入hours：");
				int hours = inScan.nextInt();
	
				stu = factoryTest.updateEmployee(SSN,
					new HourlyEmployee( firstName, lastName, SSN, wage, hours));
				break;
			}
			case 2:{
				System.out.print ("输入grossSales：");
				int grossSales = inScan.nextInt();
	
				System.out.print ("输入commissionRate：");
				double commissionRate = inScan.nextDouble();
	
				stu = factoryTest.updateEmployee (SSN,
					new CommisionEmployee( firstName, lastName, SSN, grossSales, commissionRate));
				break;
			}
			case 3:{
				System.out.print ("输入grossSales：");
				int grossSales = inScan.nextInt();
	
				System.out.print ("输入commissionRate：");
				double commissionRate = inScan.nextDouble();
	
				System.out.print ("输入baseSalary：");
				int baseSalary = inScan.nextInt();
	
				stu = factoryTest.updateEmployee (SSN, 
						new BasePlusCommisionEmployee( firstName, lastName, 
								SSN, grossSales, commissionRate, baseSalary));
				break;
			}
			default:{
				throw new Exception();
			}
		}

		System.out.println ("更新后员工信息：");
		System.out.println (stu.toString ());
		
	}
	
	private static void deleteCommand(){		
		System.out.print ("输入需要删除的员工社会保险号：");
		Employee stu = factoryTest.deleteEmployee(inScan.next().trim());
		
		if(stu == null){
			System.out.println("查无此员工，删除失败");
			return;
		}
		
		System.out.println ("刚删除的员工信息：");
		System.out.println (stu.toString ());
	}
	
	private static void printCommand(){		
		System.out.println("打印全部员工的信息：");
		factoryTest.printEmployees();
	}
	
	public static void addCommand(){
		System.out.println("--------------新增自定义员工--------------");
		System.out.print("请输入SocialSecurityNumber,(0000)以结束:");
		String SSN = inScan.next ().trim ();
		while(!SSN.equals("0000")){
			try{
				if(factoryTest.getEmployee(SSN) != null){
					System.out.println("此员工号已存在");
					throw new Exception();
				}
				
				System.out.print ("输入员工FirstNmae：");
				String firstName = inScan.next ().trim ();

				System.out.print ("输入员工LastName：");
				String lastName = inScan.next ().trim ();
				
				System.out.println("请输入员工类别：\n" +
								  "0 - SalaridEmployee\n" +
								  "1 - HourlyEmployee\n" +
								  "2 - CommisionEmployee\n" +
								  "3 - BasePlusCommisionEmployee");
				
				int type = inScan.nextInt();

				Employee stu;

				switch (type){
					case 0:{
						System.out.print("输入weeklySalary：");
						int weeklySalary = inScan.nextInt();
			
						stu = factoryTest.addEmployee(new SalaridEmployee(
								firstName, lastName, SSN, weeklySalary));
						break;
					}
					case 1:{
						System.out.print ("输入wage：");
						int wage = inScan.nextInt();
			
						System.out.print ("输入hours：");
						int hours = inScan.nextInt();
			
						stu = factoryTest.addEmployee(new HourlyEmployee( firstName, lastName, SSN, wage, hours));
						break;
					}
					case 2:{
						System.out.print ("输入grossSales：");
						int grossSales = inScan.nextInt();
			
						System.out.print ("输入commissionRate：");
						double commissionRate = inScan.nextDouble();
			
						stu = factoryTest.addEmployee (new CommisionEmployee( firstName, lastName, SSN, grossSales, commissionRate));
						break;
					}
					case 3:{
						System.out.print ("输入grossSales：");
						int grossSales = inScan.nextInt();
			
						System.out.print ("输入commissionRate：");
						double commissionRate = inScan.nextDouble();
			
						System.out.print ("输入baseSalary：");
						int baseSalary = inScan.nextInt();
			
						stu = factoryTest.addEmployee (new BasePlusCommisionEmployee( firstName, lastName, 
										SSN, grossSales, commissionRate, baseSalary));
						break;
					}
					default:{
						throw new Exception("员工种类输入错误");
					}	
				}
				
				System.out.println ("新员工信息:");
				System.out.println (stu.toString ());	
			}
			catch(Exception e){
				System.out.println(e.toString());
			}
			
			System.out.print("请输入SocialSecurityNumber,(0000)以结束:");
			SSN = inScan.next ().trim ();
		}
	}
 
	
	
	static public void main(String[] args){
        
		System.out.println("已经自动初始化10个员工信息，可以查看！！！！");
		
		inScan = new Scanner(System.in);
        
        factoryTest = new Factory();
        factoryTest.initEmployees();

        printMenu();								//打印菜单

        Boolean isQuit = false;
        int command = 0;
        
        while(!isQuit){
            
        	System.out.println("---------------------------------------------");
        	System.out.print("请输入您的操作:");
            command = inScan.nextInt();
          
            try{
                switch(command){
                    case 1:{
                        searchCommand();			//查询
                        break;
                    }
                    case 2:{
                    	updateCommand();			//更新
                        break;
                    }
                    case 3:{
                    	deleteCommand();			//删除
                    	break;
                    }
                    case 4:{
                    	printCommand();				//打印
                    	break;
                    }
                    case 5:{
                    	addCommand();
                    	break;
                    }
                    case 6:{
                    	isQuit = true;
                    	System.out.println("GOOD BYE");
                    	break;
                    }
                    default:{
                    	throw new Exception();
                    }	
                }
            }
            catch(Exception e)
            {
            	System.out.println ("发生输入错误，请按提示,正确输入！");
            }
            
            System.out.println();
            printMenu();
        }
        
        inScan.close();
    }
	
}
