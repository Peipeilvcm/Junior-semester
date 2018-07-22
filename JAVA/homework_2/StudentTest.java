import java.util.Scanner;

class StudentNumberException extends Exception {
    public StudentNumberException(String num){
        super( num + "is error");
    }
}

public class StudentTest{
    public static void main(String[] args){
        Scanner inScan = new Scanner(System.in);
        Student std;
        String stuNum, stuName;
        int[] marks = new int[3];

        while(true){
            try{
                System.out.print("������ѧ��ѧ��:");
                stuNum = inScan.next();
                
                //add StudentNumberexception
                if ('2' != stuNum.charAt(0) || '0' != stuNum.charAt(1) || 10 != stuNum.length()) {
                    throw new StudentNumberException(stuNum);
                }

                for (int i = 2; i < stuNum.length(); ++i) {
                    if (stuNum.charAt(i) > '9' || stuNum.charAt(i) < '0') {// is not digit
                        throw new StudentNumberException(stuNum);
                    }
                }

                break;
            }
            catch(StudentNumberException e){
                System.out.println("ѧ�Ÿ�ʽ����ȷ�����������룡");
            }
            catch(Exception e){
                System.out.println("ERROR INPUT!");
            }
        }

        System.out.print("������ѧ������:");
        stuName = inScan.next();
        std = new Student(stuNum, stuName);

        while(true){
            try{
                System.out.print("������ѧ�����ſγɼ�(��ѧ Ӣ�� ��ѧ)�ո�����:");
                for (int i = 0; i < 3; i++) {
                    marks[i] = inScan.nextInt();
                }

                std.enterMarks(marks[0], marks[1], marks[2]);
                
                break;
            }
            catch(ScoreException e){
                System.out.println("�ɼ������������������룡");
            }
            catch (Exception e) {
                System.out.println("ERROR INPUT!");
            }
        }
            
        System.out.println("ѧ����Ϣ����:");
        System.out.println(std.toString());
    }
}