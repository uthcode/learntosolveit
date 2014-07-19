object HelloClass {

	abstract class Person {
		def name: String
		def age: Int

		def getName(): String = {
			name
		}

		def getAge(): Int = {
			age
		}
	}

	case class PersonA(val name: String, val age: Int, val salary: Int) extends Person



}

object HelloObjectPlusClass {

    def main(args: Array[String]) {
        //val p = HelloClass
        val x = HelloClass.PersonA("Senthil", 10, 42)
        println(x.getName)
    }
}
