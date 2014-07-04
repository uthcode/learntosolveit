object TimerExample {
  /** Runs the passed in function pausing approxmimately oen second in between calls.
   * as long as the function returns true. 
   */
  def oncePerSecond(callback: () => Boolean) {
    while(callback()) {
      Thread sleep 1000
    }
  }

  /** Counts down from 0 to 1, approxmimately once per second.
   */
  def main(args: Array[String]) {
    var count = 10
    oncePerSecond(() => {println(count); count -= 1; count > 0})
  }
}
