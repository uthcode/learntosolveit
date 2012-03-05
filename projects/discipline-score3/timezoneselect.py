import pytz
import re

country_timezones = {}
for (country, tzlist) in pytz.country_timezones.iteritems():
    country_name = pytz.country_names[country]
    cities = []
    for timezone in tzlist:
        # remove continent
        city = re.sub(r'^[^/]*/', r'', timezone)
        # Argentina has an extra "Argentina/" on my system (pytz 2010b)
        city = re.sub(country_name + '/', '', city)
        # Indiana and North Dakota have different rules by country
        # change Indiana/Location to Location, Indiana
        city = re.sub(r'^([^/]*)/(.*)', r'\2, \1', city)
        # change underscores to spaces
        city = re.sub(r'_', r' ', city)
        cities.append(city)
    country_timezones[country_name] = cities

def timezone_list():
    list_of_timezones = []
    for country in sorted(country_timezones):
        for city in sorted(country_timezones[country]):
            item = "%s/%s" % (country,city)
            list_of_timezones.append(item)
    return list_of_timezones

values = []

for country, tzlist in pytz.country_timezones.iteritems():
    if len(tzlist) > 1:
        for each in tzlist:
            values.append(each)
    else:
        each = tzlist[0]
        values.append(each)

values.sort()
for each in pytz.all_timezones:
    print '<option value="%s">%s</option>' % (each, each)
