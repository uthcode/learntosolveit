import java.util.{Date, Locale}
import java.text.DateFormat._

object Today extends Application {

	override def main(args: Array[String]) {

		val now = new Date
		val frenchDateFormatter = getDateInstance(LONG, Locale.FRANCE)
		println(frenchDateFormatter format now)
		println(getDateInstance(LONG, Locale.US) format now)
		println(getDateInstance(SHORT, Locale.CHINA) format now)
	}

}

