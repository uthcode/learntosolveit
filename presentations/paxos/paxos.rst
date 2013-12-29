.. -*- coding: utf-8 -*-
.. include:: <s5defs.txt>
.. |==>| unicode:: U+02794 .. thick rightwards arrow

===============
Paxos Algorithm
===============

.. class:: center

   | A simple overview - teaser

.. class:: right small

   | - Senthil Kumaran


.. container:: handout

    This presentation gives overview Paxos algorithm.

.. contents::
   :class: handout

.. footer:: 
    http://www.uthcode.com

Paxos
=====

.. image:: https://dl.dropboxusercontent.com/s/7y89olv1btnuqs9/paxos.jpg
   :align: center
   :height: 300px
   :width: 400px

Paxos
=====

* Almost all Distributed Systems use this.
* To maintain consistency of their data admist of failures.


Production Uses
===============

* Akamai CDN
* Google -  High Replication Data stores for App Engines.
* Chubby - Distributed Lock Service for BigTable.
* IBM SAN Volume
* Apache ZooKeeper - Yahoo!


The Part Time Parliament
========================

* Decrees, Legislators,  Ledger
* A Single Law!

The Game: Consesus
==================

* Safety
* Liveness. (Eventual Consistency).

The Players
===========

* Proposers
* Acceptors
* Leaners

Election
========

* Leader Election amongst the processes

Desired Result
==============

* Consistent Result amost the processes.

Parallels
=========

* Semaphores for Multi-threaded apps.
* Variations exists on top of Basic Paxos.
* http://en.wikipedia.org/wiki/Paxos_(computer_science)
