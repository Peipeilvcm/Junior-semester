import java.util.Scanner;

public class StudentListTest{
    public static void main(String[] args){
        System.out.println("菜单如下，请输入 1~8代表您要执行的操作：\n" +
						   "1. 增加1个学生  2. 根据学号删除学生  3. 根据位置删除学生\n" +
						   "4. 判断是否为空   5.根据位置返回学生   6.根据学号返回学生\n" +
                           "7. 输出全部学生信息  8.退出程序");
        
        StudentList stuList = new StudentList(20);

        Scanner inScan = new Scanner(System.in);
        int choice = -1;
        boolean quitFlag = false;
        String stuNumTemp;
        String stuNameTemp;
        int markMathTemp;
        int markEnglishTemp;
        int markScienceTemp;
        
        while(!quitFlag){
            
            System.out.print("请输入您的操作:");
            choice = inScan.nextInt();
            try{
                switch(choice){
                    case 1:
                    {
                        System.out.println("请输入学生信息:");
                        System.out.print("学号:");
                        stuNumTemp = inScan.next();
                        System.out.print("姓名:");
                        stuNameTemp = inScan.next();
                        System.out.print("数学成绩:");
                        markMathTemp = inScan.nextInt();
                        System.out.print("英语成绩:");
                        markEnglishTemp = inScan.nextInt();
                        System.out.print("科学成绩:");
                        markScienceTemp = inScan.nextInt();

                        Student stuTemp = new Student(stuNumTemp,stuNameTemp);
                        stuTemp.enterMarks(markMathTemp,markEnglishTemp,markScienceTemp);
                        stuList.add(stuTemp);

                        stuList.printList();
                        
                        break;
                    }
                        
                    
                    case 2:
                        System.out.print("请输入学生学号以删除:");
                        if(stuList.remove(inScan.next())){
                            System.out.println("删除成功");
                            stuList.printList();
                        }
                        else{
                            System.out.println("对不起，没有对应的学生");
                        }
                        break;
                    
                    case 3:
                        System.out.print("请输入学生位置以删除:");
                        if(stuList.remove(inScan.nextInt())){
                            System.out.println("删除成功");
                            stuList.printList();
                        }
                        else{
                            System.out.println("对不起，没有对应的学生");
                        }
                        break;
                    
                    case 4:
                        if (stuList.isEmpty())
							System.out.println("学生列表为空");
						else
							System.out.println("学生列表非空");
                        break;
                    
                    case 5:
                    {
                        System.out.print("请输入学生位置:");
                        Student stuTemp = stuList.getItem(inScan.nextInt());
                        if(stuTemp==null){
                            System.out.println("对不起，没有相应的学生");
                        }
                        else{
                            System.out.println("学生信息如下:");
                            System.out.println(stuTemp.toString());
                        }
                        break;
                    }

                    case 6:
                    {
                        System.out.print("请输入学生学号:");
                        Student stuTemp = stuList.getItem(inScan.next());
                        if(stuTemp==null){
                            System.out.println("对不起，没有相应的学生");
                        }
                        else{
                            System.out.println("学生信息如下:");
                            System.out.println(stuTemp.toString());
                        }
                        break;
                    }
                    
                    case 7:
                        stuList.printList();

                        break;

                    case 8:
                        quitFlag = true;
                        break;
                    
                    default:
                    {
                        throw new Exception();
                    }
                }
            }
            catch(Exception e){
                System.out.println("ERROR INPUT");
            }
        }
    }
}