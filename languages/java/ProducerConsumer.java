/**
 * Example 94 - Producers and Consumers Communicating via a Monitor
 */

class Buffer {
    private int contents;
    private boolean empty = true;
    public int get() {
        synchronized (this) {
            while (empty)
                try  {
                    this.wait();
                } catch (InterruptedException x) {};
            empty = true;
            this.notifyAll();
            return contents;
        }
    }

    public void put(int v) {
        synchronized (this) {
            while (!empty)
                try {
                    this.wait();
                } catch (InterruptedException x) {};
            empty = false;
            contents = v;
            this.notifyAll();
        }
    }
}

class ProducerConsumer {

    public static void main(String[] args) {
        Buffer b = new Buffer();
        b.put(10);
        System.out.println(b.get());
    }

}
