"""
Title: Maximum Rectangular Area in Histogram
Video link: https://youtu.be/ZmnqCZp9bBs

Java code: https://github.com/mission-peace/interview/blob/master/src/com/interview/stackqueue/MaximumHistogram.java

"""

class MaximumHistogram:

    def maxHistogram(self, _input):
        stack = []
        max_area = 0
        area = 0
        i = 0
        while i < len(_input):
            if len(stack) == 0 or stack[-1] <= _input[i]:
                stack.append(i)
                i += 1
            else:
                top = stack.pop(-1)

                if len(stack) == 0:
                    area = _input[top] * i
                else:
                    area = _input[top] * (i - stack[-1] - 1)

            max_area = max(area, max_area)

        while stack:
            top = stack.pop(-1)

            if len(stack) == 0:
                area = _input[top] * i
            else:
                area = _input[top] * (i - stack[-1] - 1)

        max_area = max(area, max_area)

        return max_area


if __name__ == "__main__":
    _input = [2,2,2,6,1,5,4,2,2,2,2]
    mh = MaximumHistogram()
    print((mh.maxHistogram(_input)))
    assert mh.maxHistogram(_input) == 12, "Algorithm did not specify the correct result."





