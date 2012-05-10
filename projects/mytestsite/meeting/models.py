from django.db import models

class Meeting(models.Model):
    title_meeting = models.CharField(max_length=200)
    date_time = models.DateTimeField()
    location = models.CharField(max_length=200)
    requestor = models.CharField(max_length=20)
    approver = models.CharField(max_length=20)
    approve = models.IntegerField()
