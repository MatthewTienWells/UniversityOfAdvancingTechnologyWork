"""Note that a permanent log of transactions and failures is not
maintained, as they are outside the scope of the exercise. These
features, as well as transaction freezing, would be necessary for any
actual financial transaction API."""

import json

class RestAPI(object):
    """Class for tracking debts between users. Accepts GET requests
    with url '/users' any number of users as data, information on
    specified users, or all users if none are specified. Accepts
    POST requests with url '/iou' and data specifying a transaction
    between two users, returning information on the involved users.
    Also accepts POST requests with url '/add' and data containing
    a name, and adds a new user with no debts or balance, then returns
    information on the new user.
    """
    
    def __init__(self, database=None):
        self.users = {}
        self.names = []
        for user in database["users"]:
            self.users[user["name"]] = user
            self.names.append(user["name"])

    def get(self, url, payload=None):
        """Processes GET requests."""
        if url == '/users':
            if payload is None:
                return self.user_list()
            else:
                data = json.loads(payload)
                x = str(
                    {"users":[self.users[name] for name in data["users"]]}
                     )
                return x.replace("\'", "\"")

    def post(self, url, payload=None):
        """Processes POST requests."""
        data = json.loads(payload)
        if url == '/iou':
            return self.debt(data)
        if url == '/add':
            self.add_user(data['user'])
            return str(self.users[data['user']]).replace("\'", "\"")
        return self.user_list()

    def add_user(self, name):
        """Add a new user to the dictionary of users.

        Input:
            Name of the new user.
        """
        self.users[name] = {
            "name":name,
            "owes":{},
            "owed_by":{},
            "balance":0.0
            }
        self.names.append(name)

    def debt(self, data):
        """Processes a transaction between two existing users.

        Input:
            A dictionary with the following keys and values:
                lender: The user whose balance should increase.
                borrower: The user whose balance should decrease.
                amount: The amount of balance to change.
        Effects:
            The lender's 'owed_by' trait for the borrower increases
            by the amount, the borrower's 'owes' trait for the lender
            increases by the amount, the lender's balance increases by
            the amount, and the borrower's balance is decreased by the
            amount. The 'cancel_debts' method is called to simplify
            'owes' and 'owed_by' amounts for both the lender and
            borrower.
        Output:
            A json string containing information on the lender and
            borrower.
        """
        lend = data["lender"]
        borr = data["borrower"]
        amt = data["amount"]
        self.users[lend]["balance"] += amt
        self.users[borr]["balance"] -= amt
        if borr in self.users[lend]["owed_by"]:
            self.users[lend]["owed_by"][borr] += amt
            self.users[borr]["owes"][lend] += amt
        else:
            self.users[lend]["owed_by"][borr] = amt
            self.users[borr]["owes"][lend] = amt
        self.cancel_debts(lend, borr, amt)
        alp_nam = [lend, borr]
        alp_nam.sort()
        return str(
            {"users":[self.users[alp_nam[0]], self.users[alp_nam[1]]]}
            ).replace("\'", "\"")

    def cancel_debts(self, lender, borrower, amt):
        """Clears previous debts between two users if they're repaid.

        Inputs:
            The lender, borrower, and amount of the new transaction.
        Effects:
            If the lender owes the borrower an amount, decreases both
            the debt and the new transaction by each other. Whichever
            amount is 0 or less is deleted.
        """
        if borrower in self.users[lender]["owes"]:
            prv_amt = self.users[lender]["owes"][borrower]
            self.users[lender]["owes"][borrower] -= amt
            self.users[borrower]["owed_by"][lender] -= amt
            self.users[borrower]["owes"][lender] -= prv_amt
            self.users[lender]["owed_by"][borrower] -= prv_amt
        for x in [lender, borrower]:
            for y in ["owes", "owed_by"]:
                for z in [lender, borrower]:
                    try:
                        if self.users[x][y][z] <= 0:
                            del(self.users[x][y][z])
                    except KeyError:
                        pass
            
    def user_list(self):
        """Provides information on all users. (Careful: can return very
        long strings)

        Outputs:
            A json string containing information on all users.
        """
        return str(
            {"users":[self.users[name] for name in self.names]}
            ).replace("\'", "\"")
            
