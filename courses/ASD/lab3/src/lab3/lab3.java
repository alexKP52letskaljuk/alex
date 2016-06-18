package lab3;
public class lab3 {
    public static void main(String[] args){

        GeomFigure[] data = {
                new GeomFigure(1,2,3),
                new GeomFigure(3,2,4),
                new GeomFigure(5,4,2),
                new GeomFigure(1,2,9),
                new GeomFigure(6,1,1),
                new GeomFigure(4,5,5),
                new GeomFigure(9,2,6),
                new GeomFigure(3,4,3),
                new GeomFigure(1,8,2),
                new GeomFigure(2,7,3),
        };

        Hashtable hash = new Hashtable();

        for(int i = 0; i < 7; i++)
            hash.put(i, data[i]);
        System.out.println("Hash");
        hash.print();

        hash.remove(3);
        hash.remove(5);
        System.out.println("Remove elements with keys 3 and 5");
        hash.print();

        hash.put(3,data[7]);
        hash.put(5,data[8]);
        hash.put(9,data[9]);
        System.out.println("Add elements after deleting");
        hash.print();
    }
}
