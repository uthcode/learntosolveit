from django import forms

class MeetingForm(forms.Form):
    title_meeting = forms.CharField(max_length=200)
    date = forms.DateField(input_formats=["%d %m %Y"])
    time = forms.TimeField(input_formats=["%H %M"])
    location = forms.CharField(max_length=20)
