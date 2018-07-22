import java.util.Scanner;

public class FactoryTest {
	
	private static Factory factoryTest;
	
	private static Scanner inScan;
	
	private static void printMenu(){
        System.out.println(
            "--------------------------------MENU--------------------------------\n" +
            "��������1~6,ѡ���Ӧһ�����\n" +
            "1. ����Ҫ��ѯ��Ա����ᱣ�պ�,���Ա����Ϣ\n" +
            "2. �����Ѿ�������Ա���б��е�һ��Ա��,���������Ϣ�������б��е�Ա������\n" +
            "3. �����Ѿ�������Ա���б��е�һ��Ա��,�����HashMap��ɾ��\n" +
            "4. ��ӡȫ��Ա������Ϣ\n" +
            "5. �����Ա��\n" +
            "6. �˳�����\n"
        );
    }
	
	private static void searchCommand(){
        //Scanner inScan = new Scanner(System.in);
        System.out.print("����Ҫ��ѯ��Ա����ᱣ�պ�:");
        
        Employee stu = null;
        stu = factoryTest.getEmployee(inScan.next().trim());

        if (stu != null) {
            System.out.println("��Ա����Ϣ����:");
            System.out.println(stu.toString());
        } 
        else {
            System.out.println("���޴�Ա��");
        }
        //inScan.close();
    }
	
	private static void updateCommand() throws Exception{
		
		System.out.print ("������Ҫ���µ�Ա����ᱣ�պţ�");
		String SSN = inScan.next ().trim ();
		
		if(factoryTest.getEmployee(SSN) == null){
			System.out.println ("���޴�Ա��");
			return;
		}
		
		System.out.print ("����Ա��FirstNmae��");
		String firstName = inScan.next ().trim ();

		System.out.print ("����Ա��LastName��");
		String lastName = inScan.next ().trim ();
		
		System.out.println("������Ա�����\n" +
						  "0 - SalaridEmployee\n" +
						  "1 - HourlyEmployee\n" +
						  "2 - CommisionEmployee\n" +
						  "3 - BasePlusCommisionEmployee");
		
		int type = inScan.nextInt();

		Employee stu;

		switch (type){
			case 0:{
				System.out.print("����weeklySalary��");
				int weeklySalary = inScan.nextInt();
	
				stu = factoryTest.updateEmployee(SSN,
					new SalaridEmployee(
						firstName, lastName, SSN, weeklySalary));
				break;
			}
			case 1:{
				System.out.print ("����wage��");
				int wage = inScan.nextInt();
	
				System.out.print ("����hours��");
				int hours = inScan.nextInt();
	
				stu = factoryTest.updateEmployee(SSN,
					new HourlyEmployee( firstName, lastName, SSN, wage, hours));
				break;
			}
			case 2:{
				System.out.print ("����grossSales��");
				int grossSales = inScan.nextInt();
	
				System.out.print ("����commissionRate��");
				double commissionRate = inScan.nextDouble();
	
				stu = factoryTest.updateEmployee (SSN,
					new CommisionEmployee( firstName, lastName, SSN, grossSales, commissionRate));
				break;
			}
			case 3:{
				System.out.print ("����grossSales��");
				int grossSales = inScan.nextInt();
	
				System.out.print ("����commissionRate��");
				double commissionRate = inScan.nextDouble();
	
				System.out.print ("����baseSalary��");
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

		System.out.println ("���º�Ա����Ϣ��");
		System.out.println (stu.toString ());
		
	}
	
	private static void deleteCommand(){		
		System.out.print ("������Ҫɾ����Ա����ᱣ�պţ�");
		Employee stu = factoryTest.deleteEmployee(inScan.next().trim());
		
		if(stu == null){
			System.out.println("���޴�Ա����ɾ��ʧ��");
			return;
		}
		
		System.out.println ("��ɾ����Ա����Ϣ��");
		System.out.println (stu.toString ());
	}
	
	private static void printCommand(){		
		System.out.println("��ӡȫ��Ա������Ϣ��");
		factoryTest.printEmployees();
	}
	
	public static void addCommand(){
		System.out.println("--------------�����Զ���Ա��--------------");
		System.out.print("������SocialSecurityNumber,(0000)�Խ���:");
		String SSN = inScan.next ().trim ();
		while(!SSN.equals("0000")){
			try{
				if(factoryTest.getEmployee(SSN) != null){
					System.out.println("��Ա�����Ѵ���");
					throw new Exception();
				}
				
				System.out.print ("����Ա��FirstNmae��");
				String firstName = inScan.next ().trim ();

				System.out.print ("����Ա��LastName��");
				String lastName = inScan.next ().trim ();
				
				System.out.println("������Ա�����\n" +
								  "0 - SalaridEmployee\n" +
								  "1 - HourlyEmployee\n" +
								  "2 - CommisionEmployee\n" +
								  "3 - BasePlusCommisionEmployee");
				
				int type = inScan.nextInt();

				Employee stu;

				switch (type){
					case 0:{
						System.out.print("����weeklySalary��");
						int weeklySalary = inScan.nextInt();
			
						stu = factoryTest.addEmployee(new SalaridEmployee(
								firstName, lastName, SSN, weeklySalary));
						break;
					}
					case 1:{
						System.out.print ("����wage��");
						int wage = inScan.nextInt();
			
						System.out.print ("����hours��");
						int hours = inScan.nextInt();
			
						stu = factoryTest.addEmployee(new HourlyEmployee( firstName, lastName, SSN, wage, hours));
						break;
					}
					case 2:{
						System.out.print ("����grossSales��");
						int grossSales = inScan.nextInt();
			
						System.out.print ("����commissionRate��");
						double commissionRate = inScan.nextDouble();
			
						stu = factoryTest.addEmployee (new CommisionEmployee( firstName, lastName, SSN, grossSales, commissionRate));
						break;
					}
					case 3:{
						System.out.print ("����grossSales��");
						int grossSales = inScan.nextInt();
			
						System.out.print ("����commissionRate��");
						double commissionRate = inScan.nextDouble();
			
						System.out.print ("����baseSalary��");
						int baseSalary = inScan.nextInt();
			
						stu = factoryTest.addEmployee (new BasePlusCommisionEmployee( firstName, lastName, 
										SSN, grossSales, commissionRate, baseSalary));
						break;
					}
					default:{
						throw new Exception("Ա�������������");
					}	
				}
				
				System.out.println ("��Ա����Ϣ:");
				System.out.println (stu.toString ());	
			}
			catch(Exception e){
				System.out.println(e.toString());
			}
			
			System.out.print("������SocialSecurityNumber,(0000)�Խ���:");
			SSN = inScan.next ().trim ();
		}
	}
 
	
	
	static public void main(String[] args){
        
		System.out.println("�Ѿ��Զ���ʼ��10��Ա����Ϣ�����Բ鿴��������");
		
		inScan = new Scanner(System.in);
        
        factoryTest = new Factory();
        factoryTest.initEmployees();

        printMenu();								//��ӡ�˵�

        Boolean isQuit = false;
        int command = 0;
        
        while(!isQuit){
            
        	System.out.println("---------------------------------------------");
        	System.out.print("���������Ĳ���:");
            command = inScan.nextInt();
          
            try{
                switch(command){
                    case 1:{
                        searchCommand();			//��ѯ
                        break;
                    }
                    case 2:{
                    	updateCommand();			//����
                        break;
                    }
                    case 3:{
                    	deleteCommand();			//ɾ��
                    	break;
                    }
                    case 4:{
                    	printCommand();				//��ӡ
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
            	System.out.println ("������������밴��ʾ,��ȷ���룡");
            }
            
            System.out.println();
            printMenu();
        }
        
        inScan.close();
    }
	
}
