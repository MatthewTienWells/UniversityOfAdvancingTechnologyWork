def total(basket):
    bundles = {1:800,2:1520,3:2160,4:2560,5:3000} #Price for each bundle
    count = [0, 0, 0, 0, 0] #Number of each book
    for book in basket: 
        count[book-1] += 1 #Count the number of each book
    while 0 in count:
        count.remove(0)
    groups_count = {1:0,2:0,3:0,4:0,5:0} #Number of bundles we can make
    while len(count) > 0:
        #This is the limit on the number of bundles we can make of a size.
        x = min(count)
        #Increase the number of bundles we can make with the remaining books
        groups_count[len(count)] = x
        for num in range(len(count)):
            #Remove the books we made the bundle from from the count
            count[num] -= x
        while 0 in count:
            #Delete books with a count of zero
            count.remove(0)
    #Bundles of 4 are cheaper than the average of bundles of 3 and 5,
    #so we'll use them instead.
    while groups_count[3] > 0 and groups_count[5] > 0:
        groups_count[3] -= 1
        groups_count[5] -= 1
        groups_count[4] += 2
    price = 0
    #Calculate the total price.
    for num in groups_count:
        price += bundles[num]*groups_count[num]
    return price
