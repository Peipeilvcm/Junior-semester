import java.util.Scanner;

public class StudentTest{
    public static void main(String[] args){
        Scanner inScan = new Scanner(System.in);
        System.out.printf("请输入学生学号:");
        String stuNum = inScan.next();
        System.out.printf("请输入学生姓名:");
        String stuName = inScan.next();

        Student std = new Student(stuNum, stuName);
        
        System.out.print("请输入学生三门课成绩(数学 英语 科学)空格区分:");
        int[] marks = new int[3];
        for(int i=0;i<3;i++){
            marks[i] = inScan.nextInt();
        }

        try{
            std.enterMarks(marks[0],marks[1],marks[2]);
            System.out.println("学生信息如下:");
            System.out.println(std.toString());
        }
        catch(Exception e){
            System.out.println("ERROR INPUT!");
        }
        
    }
}