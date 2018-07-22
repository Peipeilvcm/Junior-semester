class ScoreException extends Exception{
    public ScoreException(int mark){
        super( mark + "is error" );
    }
}

public class Student{
    //成绩的边界与特殊值
    static public final int NoMark = -1;
    static public final int MaxMark = 100;
    static public final int MinMark = 0;

    private String studentNum;
    private String studentName;
    private int markForMath;
    private int markForEnglish;
    private int markForScience;

    public Student(String num, String name){
        studentNum = num;
        studentName = name;
        markForMath = NoMark;
        markForEnglish = NoMark;
        markForScience = NoMark;
    }
    public Student(){
        markForMath = NoMark;
        markForEnglish = NoMark;
        markForScience = NoMark;
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


    public void enterMarks(int markForMath, int markForEnglish, int markForScience)
            throws ScoreException{
        //add ScoreException
        if( markForMath > MaxMark || markForMath < MinMark ){
            throw new ScoreException(markForMath);
        }
        if( markForEnglish > MaxMark || markForEnglish < MinMark ){
            throw new ScoreException(markForEnglish);
        }
        if( markForScience > MaxMark || markForScience < MinMark ){
            throw new ScoreException(markForScience);
        }

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