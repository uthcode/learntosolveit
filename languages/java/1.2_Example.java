/* Execute this as 
 * javac filename.java
 * java Test Hello World 
 */

class Test {
	public static void main(String[] args) {
		for(int i = 0; i < args.length; i++) {
			System.out.print(i == 0 ? args[i] : " " + args[i]);
		}
		System.out.println();
	}
}