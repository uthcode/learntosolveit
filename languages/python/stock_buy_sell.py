
CAPITAL = 10000
DESIRED_PROFIT = 100


def get_sell_price(buy):
    units = CAPITAL // buy
    sell_price = (CAPITAL + DESIRED_PROFIT) // buy
    return sell_price

