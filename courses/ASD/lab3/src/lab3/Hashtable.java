/**
 * This class implements a hash table as an associative array of entries. Hash
 * table does not resolve any collisions
 *
 */
package lab3;
public class Hashtable {
    class Entry{
        int key;
        GeomFigure value;
        boolean deleted = false;

        public Entry(int key, GeomFigure value) {
            this.key = key;
            this.value = value;
        }
    }

    private Entry[] table;


    private int size;

    private static final int initialCapacity = 11;

    private double criticalLoadFactor;
    private static final double defaultLoadFactor = 0.75;

    private final double A = Math.sqrt(5) - 2;

    private int hash(int key) {
        return (int)Math.floor(table.length * (A * key - Math.floor(A*key)));
    }


    public Hashtable(int initialCapacity, double loadFactor) {
        table = new Entry[initialCapacity];
        for(int i = 0; i < initialCapacity; i++)
            table[i] = new Entry(0, null);
        this.criticalLoadFactor = loadFactor;
    }


    public Hashtable(int initialCapacity) {
        this(initialCapacity,defaultLoadFactor);
    }

    public Hashtable() {
        this(initialCapacity,defaultLoadFactor);
    }

    public boolean isEmpty() {
        return size == 0;
    }

    private double getLoadFactor() {
        return ((double) size) / table.length;
    }


    public int size() {
        return size;
    }


    private int hp(int hash, int probe){
        return (hash + probe * probe) % table.length;
    }

    private void putToNewTable(int key, GeomFigure v){
        int h = hash(key);
        for(int probe =  0; probe < table.length; probe++){
            int probePos = hp(h, probe);
            if(table[probePos].value == null){
                table[probePos] = new Entry(key,v);
                break;
            }
        }
    }

    private void rehash() {
        Entry[] old_table =  table;
        table = new Entry[table.length * 2];
        for(int i = 0; i < table.length; i++)
            table[i] = new Entry(0,null);

        for(int i = 0; i < old_table.length; i++){
            if(old_table[i].value != null && !old_table[i].deleted)
                putToNewTable(old_table[i].key, old_table[i].value);
        }
    }


    public GeomFigure get(int k) {
        int h = hash(k);
        for(int probe = 0; probe < table.length; probe++){
            int probePos = hp(h, probe);
            if(table[probePos].key == k && !table[probePos].deleted)
                return table[probePos].value;
            else if(table[probePos].value == null && !table[probePos].deleted)
                return null;
        }
        return null;
    }

    public boolean contains(int key){
        return get(key) != null;
    }

    public GeomFigure put(int key, GeomFigure value) {
        size++;
        while (getLoadFactor() >= criticalLoadFactor)
            rehash();

        int h = hash(key);
        for(int probe = 0; probe < table.length; probe++){
            int probePos = hp(h, probe);
            if(table[probePos].value == null || table[probePos].deleted){
                table[probePos] = new Entry(key,value);
                return null;
            } else if(table[probePos].key == key){
                GeomFigure old = table[probePos].value;
                table[probePos] = new Entry(key,value);
                return old;
            }
        }

        return null;

    }

    public GeomFigure remove(int key) {
        int h = hash(key);
        for(int probe = 0; probe < table.length; probe++){
            int pos  = hp(h,probe);
            if(table[pos].key == key && !table[pos].deleted){
                GeomFigure tmp = table[pos].value;
                table[pos].value = null;
                table[pos].deleted = true;
                size--;
                return tmp;
            } else if(table[pos].value == null && !table[pos].deleted)
                return null;
        }

        return null;

    }

    public void print(){
        for(int i = 0; i  < table.length; i++){
            if(table[i].value != null){
                System.out.println("On pos "+i+": key \""+table[i].key+"\" value \""+table[i].value+"\"");
            }
        }
    }

}