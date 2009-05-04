from django.db import models
from django.db.models import permalink
from django.contrib import admin

from gallery.items.fields import ThumbnailImageField

class Item(models.Model):
    name = models.CharField(max_length=250)
    description = models.TextField()

    class Meta:
        ordering = ['name']
        
    def __unicode__(self):
        return self.name
        
    @permalink
    def get_absolute_url(self):
        return ('item_detail', None, {'object_id': self.id})

class Photo(models.Model):
    item = models.ForeignKey(Item)
    title = models.CharField(max_length=100)
    image = ThumbnailImageField(upload_to='photos')
    caption = models.CharField(max_length=250, blank=True)
        
    class Meta:
        ordering = ['title']
        
    def __unicode__(self):
        return self.title

    @permalink
    def get_absolute_url(self):
        return ('photo_detail', None, {'object_id': self.id})

class PhotoInline(admin.StackedInline):
    model = Photo

class ItemAdmin(admin.ModelAdmin):
    inlines = [PhotoInline]

admin.site.register(Item, ItemAdmin)    
admin.site.register(Photo)
