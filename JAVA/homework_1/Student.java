public class Student{
    private String studentNum;
    private String studentName;
    private int markForMath;
    private int markForEnglish;
    private int markForScience;

    public Student(String num, String name){
        studentName = name;
        studentNum = num;
        markForMath = -1;
        markForEnglish = -1;
        markForScience = -1;
    }
    public Student(){
        markForMath = -1;
        markForEnglish = -1;
        markForScience = -1;
    }

    public String getNum(){
        return studentNum;
    }
    public String getName(){
        return studentName;
    }

    public int getMathMark(){
        return markForMath;
    }
    public int getEnglishMark(){
        return markForEnglish;
    }
    public int getScienceMark(){
        return markForScience;
    }

    public void enterMarks(int markForMath,
                         int markForEnglish,
                         int markForScience){
        this.markForMath = markForMath;
        this.markForEnglish = markForEnglish;
        this.markForScience = markForScience;
    }

    public double calAverage(){
        return (markForEnglish+markForMath+markForScience)/3.0;
    }

    public String toString(){
        String temp;
        temp = String.format("学号:%s\n"+"姓名:%s\n"+
                            "数学成绩:%d\n"+"英语成绩:%d\n"+
                            "科技成绩:%d\n"+"平均成绩:%.2f",
                             studentNum,studentName,markForMath,
                             markForEnglish,markForScience,calAverage());
        
        return temp;
    }

}