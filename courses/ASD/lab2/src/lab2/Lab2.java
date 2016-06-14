package lab2;

import java.util.Arrays;

public class Lab2 {
    static void checkSorted(Student[] arr){
        for(int i = 0; i < arr.length - 1; i++){
            if(arr[i].compare(arr[i+1]) > 0) System.out.println("Array is not sorted:" + " elements are \"" + arr[i] +"\" and \""+arr[i+1] + "\"");
        }

    }

    static void printArray(Student[] arr){
        for(int i = 0; i < arr.length; i++)
            System.out.println(arr[i]);
    }

    static void swap(Student[] arr,int i, int j){
        Student tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void bubbleSort(Student[] arr){
        boolean swapped;
        int l = 0;
        int r = arr.length - 1;
        do {
            swapped = false;
            for(int i = l; i < r; i++)
                if(arr[i].compare(arr[i+1])>0) {
                    swap(arr, i, i + 1);
                    swapped = true;
                }
            r--;
            for(int i = r; i > l; i--)
                if(arr[i].compare(arr[i-1])<0){
                    swap(arr, i, i - 1);
                    swapped = true;
                }
            l++;
        } while(l < r && swapped);
    }

    public static void refSort(StudentLL students){
        int i,n;
        n = students.size();
        SLLNode node = students.getHead();
        SLLNode tail = students.getTail();
        Student[] tmp_arr = new Student[students.size()];
        for(i =0,node = node.next; node != tail; node = node.next, i++)
            tmp_arr[i] = node.data;
        students.clear();
        bubbleSort(tmp_arr);
        for(i = 0; i < n; i++)
            students.addLast(tmp_arr[i]);
    }


    public static void main(String[] args){
        Student[] students;
        Student[] orig_students = {
                new Student("Lena","Ruban",false,183.270),
                new Student("Vasia","Haishnik",true,162.680),
                new Student("Petro","Hlunovskiy",false,166.295),
                new Student("Valentun","Voitovuch",true,165.780),
                new Student("Vania","Azman",false,167.620),
                new Student("Anton","Mazun",false,167.955),
                new Student("Gendalf", "White", true, 183.270),//Test equal elements
          };
        System.out.println("Original array:");
        printArray(orig_students);
        System.out.println("Bubble sort by raiting, then surname");
        students = Arrays.copyOf(orig_students,orig_students.length);
        bubbleSort(students);
        checkSorted(students);
        printArray(students);

        System.out.println("######### Reference sort ###########");
        StudentLL studentLL = new StudentLL();
        for(int i = 0; i  < orig_students.length; i++)
            studentLL.addLast(orig_students[i]);
        refSort(studentLL);
        for(SLLNode node = studentLL.getHead().next;
            node != studentLL.getTail().prev; node = node.next){
            if(node.data.compare(node.next.data) > 0)
                System.out.println("Array is not sorted");
        }
        for(SLLNode node = studentLL.getHead().next;
                node != studentLL.getTail(); node = node.next){
            System.out.println(node.data);
        }
    }
}