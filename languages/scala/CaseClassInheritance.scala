object CaseClassInheritance {
  abstract class Person {
    def name: String
    def age: Int
    // address and other properties
    // methods (ideally only accessors since it is a case class)
    def getName(): String =  {
      return name
    }
  }

  case class Employer(val name: String, val age: Int, val taxno: Int)
      extends Person

  case class Employee(val name: String, val age: Int, val salary: Int)
      extends Person

  case class PersonA(val name: String, val age: Int, val salary: Int) extends Person

  def main(args: Array[String]) {
        val p = PersonA("Senthil",10,42)
        println(p.getName)
  }
}
