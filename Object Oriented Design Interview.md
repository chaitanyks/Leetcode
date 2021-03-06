An Object Oriented Design Interview usually lasts for 45-60 minutes. The following template will guide you (with a basic example to get you an idea) on how to manage time duration across various aspects of it -

โ๐๐๐ช๐ฎ๐ข๐ซ๐๐ฆ๐๐ง๐ญ ๐๐ฅ๐๐ซ๐ข๐๐ข๐๐๐ญ๐ข๐จ๐ง๐ฌ (3-5 mins)

The OOD interview questions are often abstract and vague. Always ask clarifying questions to understand the problem and find the exact scope of the system that the interviewer has in mind.

๐ Focussed use cases to cover (MVP)
๐ Use cases that will not be covered
๐ Who will use the system (Actors)
๐ How the system will be used

eg. Let's design an online shopping site. Few requirements would be -

๐Users should be able to search products based on name.
๐Users should be able to view/buy products.
๐Users should be able to add/remove product items in their shopping cart.
๐User can place an order.
๐Users should get notifications about order.
๐User should be able to pay through diff modes.

โ Use cases to cover (3-6 mins)

You are expected to find possible actors of the system and write down different use cases the system will support.

๐Actors could be - Customer, Admin, System

Some of the use cases could be -

๐ Search products based on the name.
๐ add/remove/modify products in the shopping cart.
๐ Check out to buy items in the shopping cart.
๐ Make payment to place an order
๐ Send notification to user about the order.

โ Identify the Core classes (3-6 mins)

After gathering requirements and drafting a few use cases, our understanding of what we are designing becomes clear. Now we should consider what could be the main classes of the system. You are expected to sketch a class diagram or write down class names.

The way to identify classes or entities is -

๐Nouns in the requirements are possible candidates for Classes.

Some of the core classes could be -

๐Product
๐ Item
๐ User
๐ ShoppingCart
๐ Order
๐ Payment
๐ Notification

โ Identify the fields/properties of each class (5-10 mins)

Once we know the core classes/objects of the system, it is expected to draw a class diagram along with class fields. Take each class identified in the above steps and add a few important properties which drive the use cases of the system.
eg.

๐ Product

name
description
price
๐ User

name
email
phone
etc...

โ Identify the relationship between the classes (5-10 mins)

Once we know the core classes/objects of the system, it is expected to draw what is the relationship between the classes. The relationship mainly focuses on is-a and has-a between classes. The different types of relationships to draw or write are -

๐ Are there any classes that are very generic and more concrete classes that can be sketched.
๐ Are there any one to one, one to many, and many to many relationships between the classes.
eg.

๐ Customer, Guest, and Admin inherit from User
๐ Customer has One Shopping Cart
๐ Shopping Cart has Many Items
etc ...

โ Identify the possible actions of the classes (5-10 mins)

Once we are clear with the requirements, use cases and possible design of the system, etc, it is time to identify the different actions classes will perform based on their relationship.

The way to identify class actions is -

๐ Verbs in the requirements/use cases are possible candidates for actions these classes perform. Those can be taken as methods of the classes.
eg.

๐ Customer can add the item to shopping cart - addItemToCart(Item item)
๐ Customer can place an order - placeOrder(Order order)
etc...

โ Code (5-8 mins) (Optional)

The interviewer will ask you to write code for a specific use case by taking the above classes. The class diagram will give you an idea about the class's name, fields, and methods. You are expected to write code for the methods which fulfill the use case interviewer wants or any algorithm/data structure which handles certain use cases.

โ ๐๐๐ฌ๐จ๐ฅ๐ฏ๐ ๐๐จ๐ญ๐ญ๐ฅ๐๐ง๐๐๐ค๐ฌ ๐๐ง๐ ๐๐จ๐ฅ๐ฅ๐จ๐ฐ-๐ฎ๐ฉ ๐ช๐ฎ๐๐ฌ๐ญ๐ข๐จ๐ง๐ฌ (3-4 mins)
