public class StudentList{
    private Student[] list;//存储对象学生对象
    private int total;

    public StudentList(int length){
        total = 0;
        list = new Student[length];
    }

    public boolean add(Student stu){
        if(total == list.length)
            return false;
        else{
            list[total++] = stu;
            return true;
        }
    }

    public boolean remove(int no){
        if(no > total || no <= 0){
            return false;
        }

        for(int j = no-1; j < total-1; ++j){
            list[j]=list[j+1];
        }
        
        total--;
        list[total] = null;

        return true;
    }

    public boolean remove(String number){
        int numloc = -1;
        for(int i = 0; numloc == -1 && i < total; ++i){
            if(list[i].getNum()==number){
                numloc = i;//找到该学号学生
            }
        }
        if(numloc == -1){
            return false;
        }
        else{
            return this.remove(numloc+1);
        }
    }

    public boolean isEmpty(){
        return total == 0;
    }

    public Student getItem(int no){
        if(no > total || no<= 0){
            return null;
        }
        else{
            return list[no-1];
        }
    }

    public Student getItem(String number){
        for(int i = 0; i < total; ++i){
            if(list[i].getNum() == number){
                return list[i];
            }
        }
        return null;
    }

    public int getTotal(){
        return total;
    }
	
	public void printList(){
		System.out.println("---目前有" +getTotal() + "个学生，信息为---");
		for (int i = 0; i < getTotal(); i++)
            System.out.println(getItem(i + 1).toString());
	}
}