from django.forms import ModelForm
from models import Meeting

from django.forms.widgets import DateTimeInput, Textarea, TextInput

class MeetingForm(ModelForm):
    class Meta:
        model = Meeting
        fields = ('title_meeting', 'date_time', 'location')
        widgets = {
            'name': TextInput(),
            'date_time': DateTimeInput(),
            'location': TextInput()
        }

