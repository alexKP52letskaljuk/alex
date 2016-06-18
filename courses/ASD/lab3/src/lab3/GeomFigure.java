package lab3;
public class GeomFigure {
    private double centreX;
    private double centreY;
    private double radius;

    public GeomFigure(double centreX, double centreY, double radius) {
        this.centreX = centreX;
        this.centreY = centreY;
        this.radius = radius;
    }

    public double getArea(){
        return Math.PI * radius * radius;
    }

    public double getLength(){
        return 2 * Math.PI * radius;
    }

    @Override
    public String toString(){
        return "circle("+centreX+","+centreY+") r="+radius+";area="+getArea()+";length="+getLength();
    }
}
