# QSecureTwin — Final Project View

## 1. The Main Aim of Our Project

The aim of **QSecureTwin** is to build a system that helps enterprises prepare for **Post-Quantum Cryptography (PQC) migration**.

The project will ultimately answer:

1. **How vulnerable is each cryptographic asset to quantum threats?**
2. **Which PQC algorithm should be recommended?**
3. **How urgent is the migration?**
4. **What migration-related risks or outcomes can be expected?**
5. **After understanding all assets, how should the enterprise plan its migration?**

---

# 2. The Project Has Two Major Phases

## PHASE 1 / THIS SEMESTER

### Goal:

> **Build the complete ML prediction engine using the existing dataset.**

In this phase, we will work with the given dataset and train models for **all available target outputs**.

### Flow

```text
EXISTING DATASET
       ↓
Understand the Data
       ↓
EDA
       ↓
Data Preprocessing
       ↓
Feature Engineering
       ↓
Train ML Models
       ↓
Evaluate and Compare Models
       ↓
Select Best Models
       ↓
Save Complete ML Pipeline
```

---

## What will the ML models predict?

Using the input features available in the dataset, we will train models to predict:

### A. Quantum Risk and PQC Decision

1. **Quantum Risk Score**
2. **Risk Category**
3. **Recommended PQC Algorithm**
4. **Migration Priority**
5. **Recommended Migration Stage**

### B. Migration Outcome and Risk Prediction

6. **Migration Success**
7. **Rollback Required**
8. **Downtime Risk**
9. **Compatibility Risk**
10. **Estimated Migration Duration**

So, by the end of this semester, our ML system should conceptually work like this:

```text
ASSET INFORMATION
       ↓
PREPROCESSING
       ↓
TRAINED ML MODELS
       ↓
┌───────────────────────────────────┐
│ Quantum Risk Score                │
│ Risk Category                     │
│ Recommended PQC Algorithm         │
│ Migration Priority                │
│ Migration Stage                   │
│ Migration Success                 │
│ Rollback Required                 │
│ Downtime Risk                     │
│ Compatibility Risk                │
│ Migration Duration                │
└───────────────────────────────────┘
```

### Final outcome of Phase 1

> **A complete trained and evaluated ML prediction engine for all target outputs available in the dataset.**

---

# PHASE 2 / NEXT SEMESTER

### Goal:

> **Take the ML models built in Phase 1 and turn them into a practical enterprise PQC migration decision-support system.**

This is where the project goes **beyond simply predicting dataset outputs**.

---

# 3. What Will We Do in Phase 2?

## Step 1 — Take new/real-world enterprise data

Instead of only using the existing dataset:

```text
Dataset → ML Training
```

we will allow:

```text
Enterprise / User Data
        ↓
QSecureTwin System
```

For example, an enterprise may provide information about many cryptographic assets.

---

## Step 2 — Use the ML models built in Phase 1

```text
NEW ENTERPRISE DATA
        ↓
Data Validation
        ↓
Same Preprocessing Pipeline
        ↓
Saved ML Models
        ↓
Predictions for Every Asset
```

So if an enterprise provides 100 assets:

```text
Asset 1 → All 10 predictions
Asset 2 → All 10 predictions
Asset 3 → All 10 predictions
...
Asset 100 → All 10 predictions
```

---

# 4. What Happens Beyond Prediction?

This is where the project becomes more useful.

After predicting the outputs for all assets, we will use the predictions to build **enterprise-level insights and planning features**.

## 1. Enterprise Risk Overview

Instead of looking at assets one by one, the system will analyze the entire organization.

For example:

```text
Total Assets: 500

Critical Risk: 45
High Risk: 120
Medium Risk: 200
Low Risk: 135
```

The system can generate:

* Overall enterprise risk level
* Number of assets in each risk category
* High-risk areas
* Assets requiring immediate attention

---

## 2. Asset Prioritization

We will use predictions such as:

* Quantum Risk Score
* Risk Category
* Migration Priority
* Migration Stage
* Downtime Risk
* Compatibility Risk
* Estimated Duration

to identify which assets should receive attention first.

For example:

```text
Priority Order

1. Asset A
2. Asset F
3. Asset C
4. Asset B
5. Asset D
```

This priority order is an **additional result created by our system**.

---

## 3. Migration Roadmap Generation

Instead of showing only:

```text
Asset A → Critical
```

the system will organize assets into a usable roadmap.

Example:

```text
PHASE 1
--------
Assets requiring immediate attention

PHASE 2
--------
High-priority assets

PHASE 3
--------
Medium-priority assets

PHASE 4
--------
Remaining assets
```

The exact logic for grouping can be developed and improved in Phase 2.

---

## 4. Risk-Aware Migration Planning

The system can consider multiple predictions together.

For example:

```text
Asset A
--------
Quantum Risk: Critical
Priority: Immediate
Downtime Risk: High
Compatibility Risk: Medium
Duration: 15 days
```

This means the system should not just say:

> "Migrate immediately."

It can also provide a more meaningful interpretation:

> **High quantum risk and immediate priority, but migration should be carefully planned because of high downtime risk and long estimated duration.**

This type of **combined decision insight** makes the output more useful than displaying 10 independent predictions.

---

# 5. Additional Features That Can Make the Project Stand Out

These can be developed in Phase 2.

## A. Interactive Dashboard

Show:

* Enterprise quantum risk distribution
* Number of assets by risk
* PQC algorithm recommendations
* Priority distribution
* Migration stages
* High-risk assets

---

## B. Personalized Migration Roadmap

Instead of a generic recommendation, generate a roadmap based on the enterprise's own data.

```text
Your Enterprise

Stage 1 → 15 Critical Assets
Stage 2 → 40 High-Risk Assets
Stage 3 → 100 Medium-Risk Assets
Stage 4 → Remaining Assets
```

---

## C. Explainable AI

For each prediction, show **why** the model made that decision.

Example:

```text
Asset A was classified as Critical because:

• Weak/legacy cryptographic algorithm
• High business criticality
• High exposure
• Large blast radius
```

This can make the system more transparent and useful for enterprise decision-making.

---

## D. What-If Analysis

This could be a strong feature.

The user can change an asset property and see how the prediction changes.

Example:

```text
Current Key Size = 2048
        ↓
Predicted Risk = Critical

Change Key Size = 4096
        ↓
Recalculate
        ↓
New Predicted Risk = High
```

This allows users to explore:

> **"What happens if I change this configuration?"**

---

## E. Migration Simulation

The system could allow users to simulate different migration scenarios.

Example:

```text
Scenario A
--------
Migrate all critical assets first

Scenario B
--------
Migrate by business unit

Scenario C
--------
Migrate lowest downtime-risk assets first
```

Then compare:

* Number of assets handled
* Estimated duration
* Downtime risk
* Compatibility risk
* Overall remaining quantum risk

This can be a particularly strong feature because it moves from **prediction → decision support**.

---

## F. Progress Tracking

Once an enterprise begins migration:

```text
Total Assets: 500

Migrated: 150
Remaining: 350

Critical Assets Remaining: 12
```

The roadmap and enterprise risk level can update as assets are migrated.

---

# 6. Complete Project Flow

```text
════════════════════════════════════
PHASE 1 — ML PREDICTION ENGINE
════════════════════════════════════

Existing Dataset
       ↓
EDA
       ↓
Preprocessing
       ↓
Feature Engineering
       ↓
Train Models for ALL Outputs
       ↓
Evaluate Models
       ↓
Select Best Models
       ↓
Save ML Pipeline


════════════════════════════════════
PHASE 2 — REAL-WORLD DECISION SYSTEM
════════════════════════════════════

New Enterprise Data
       ↓
Validate and Process Data
       ↓
Use Saved ML Models
       ↓
Predict All Outputs
       ↓
────────────────────────────
        BEYOND PREDICTION
────────────────────────────
       ↓
Enterprise Risk Analysis
       ↓
Compare All Assets
       ↓
Prioritize Assets
       ↓
Generate Migration Roadmap
       ↓
Risk-Aware Recommendations
       ↓
Dashboard and Visualization
       ↓
What-If Analysis / Simulation
       ↓
Progress Tracking
```

---

# 7. The Exact Difference Between the Two Phases

| Phase 1 — This Semester     | Phase 2 — Next Semester            |
| --------------------------- | ---------------------------------- |
| Work with existing dataset  | Work with new/real enterprise data |
| Train all ML models         | Use saved ML models                |
| Predict all dataset targets | Predict outputs for user assets    |
| Evaluate model performance  | Build real-world application       |
| Compare ML algorithms       | Analyze enterprise as a whole      |
| Save models                 | Prioritize assets                  |
| Build ML foundation         | Generate migration roadmap         |
| —                           | Dashboard                          |
| —                           | Explainability                     |
| —                           | What-if analysis                   |
| —                           | Migration simulation               |
| —                           | Progress tracking                  |

---

# 8. Final Project Aim

The project can now be summarized as:

> **QSecureTwin is an ML-based decision-support system for Post-Quantum Cryptography migration. In Phase 1, we develop and evaluate machine learning models to predict quantum risk, PQC recommendations, migration priority, migration stages, and migration-related outcomes using the available dataset. In Phase 2, these trained models are applied to new enterprise data and extended with enterprise-level analysis, asset prioritization, migration roadmap generation, explainability, simulation, and interactive decision-support features.**

## In one sentence

> **Phase 1 teaches the system to understand and predict the PQC migration status of an asset; Phase 2 turns those predictions into a practical tool that helps an enterprise understand, plan, simulate, and manage its journey toward post-quantum cryptography.**



| Area                             | What existing work already does                                        | What is missing / our gap                                                         | What our project will do                                                                   |
| -------------------------------- | ---------------------------------------------------------------------- | --------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| **1. Asset Discovery**           | Helps companies find their cryptographic assets                        | Finding assets alone does not give complete information about their migration     | Our system will analyze the available information about each asset                         |
| **2. Risk Assessment**           | Existing methods can identify quantum risk                             | They may only focus on risk                                                       | Our system will predict **risk along with other migration information**                    |
| **3. PQC Recommendation**        | Existing standards/frameworks suggest which PQC algorithms can be used | Recommendation may not be combined with all other asset predictions in one system | Our system predicts/recommends a **PQC algorithm for each asset**                          |
| **4. Migration Priority**        | Existing methods can help decide which assets should be migrated first | Priority can be handled separately from other analysis                            | Our system predicts **migration priority together with risk and other outputs**            |
| **5. Migration Problems**        | Existing work discusses problems like compatibility and downtime       | These factors are not always predicted together for every asset                   | Our system predicts **success, rollback, downtime risk, compatibility risk, and duration** |
| **6. Complete Asset View**       | Different methods may analyze different aspects                        | User may need to look at multiple results separately                              | Our system gives **one complete prediction profile for each asset**                        |
| **7. Enterprise-Level Analysis** | Existing frameworks provide general migration guidance                 | We want to use predictions from all assets together                               | Our system will analyze the **overall enterprise situation**                               |
| **8. Explainability**            | Some systems may give a result without clearly explaining it           | Users may not understand *why* a prediction was made                              | Our system can explain **why an asset received a particular prediction**                   |
| **9. What-If Analysis**          | Most assessments analyze the current situation                         | Users cannot easily test changes                                                  | Our system can let users change inputs and see **how predictions change**                  |
| **10. Migration Simulation**     | Existing frameworks provide migration guidance                         | Users may not be able to interactively compare different strategies               | Our system can compare **different migration scenarios**                                   |
| **11. Integrated System**        | Existing work may provide frameworks or solve individual problems      | Different tasks can remain separate                                               | Our project aims to bring them together in **one practical system**                        |
