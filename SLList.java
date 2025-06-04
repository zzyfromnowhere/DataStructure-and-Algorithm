public class SLList {
    /* static means it won't use methods outside of it */
    private static class IntNode {
        public int item;
        public IntNode next;

        public IntNode(int i, IntNode n)
        {
            this.item = i;
            this.next = n;
        }
    }

    /*The first item(if exists) is at sentinel.next*/
    private IntNode sentinel;
    private int size;


    //constructor with parameter
    public SLList(int x){
        sentinel = new IntNode(63, null);
        sentinel.next = new IntNode(x, null);
        this.size++;
    }
    //constructor with empty parameter list
    public SLList(){
        sentinel = new IntNode(63, null);
        this.size = 0;
    }

    //if the list is empty??
    public boolean isEmpty(){
        if(this.sentinel.next == null) return true;
        return false;
    }

    //print the list
    public void printList(){
        if(isEmpty()){
            System.out.println("The list is empty");
            return;
        }
        IntNode p = sentinel.next;
        System.out.print(p.item + " ");
        while(p.next != null){
            System.out.print(p.next.item + " ");
            p = p.next;
        }
    }

    //add x to the front of the list
    public void addFirst(int x){
        sentinel.next = new IntNode(x, sentinel.next);
        this.size ++;
    }

    //add x to the last of the list
    public void addLast(int x){
        IntNode p = sentinel;
        while(p.next != null){
            p = p.next;
        }
        p.next = new IntNode(x, null);
        this.size ++;
    }

    //returns the first item in the list
    public int getFirst(){
        return sentinel.next.item;
    }

    //returns the last item in the list
    public int getLast(){
        IntNode p = this.sentinel;
        while(p.next != null){
            p = p.next;
        }
        return p.item;
    }

    //returns the size of this list
    public int size(){
        return this.size;
    }
}
