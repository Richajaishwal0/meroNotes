# Quantum-Safe Migration Platform — Module Guide

## 1. Project Goal

The goal of this project is to build a platform that helps organizations move from vulnerable or quantum-insecure cryptographic systems toward **post-quantum cryptography (PQC)**.

The platform should not stop at saying:

> "Your organization has high quantum risk."

It should help answer the complete journey:

```text
What cryptography do we have?
        ↓
Which assets are vulnerable?
        ↓
How serious is the quantum risk?
        ↓
Which assets should we migrate first?
        ↓
What PQC strategy should we consider?
        ↓
How difficult or expensive could migration be?
        ↓
What steps should we follow?
        ↓
How do we track migration progress?
```

The project can therefore be viewed as a **Quantum-Safe Migration Decision Support Platform**.

---

# 2. Overall System Flow

```text
                    QUANTUM-SAFE MIGRATION PLATFORM

                              ┌───────────────┐
                              │ User / Admin  │
                              └───────┬───────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 1. Asset Discovery &   │
                         │    Automated Ingestion  │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 2. Cryptographic       │
                         │    Inventory            │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 3. Quantum Risk        │
                         │    Assessment            │
                         │       [ML Models]       │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 4. Migration Priority  │
                         │    Engine               │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 5. PQC Recommendation  │
                         │    & Strategy Engine    │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 6. Cost & Performance  │
                         │    Impact Analyzer      │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 7. Migration Roadmap   │
                         │    Generator             │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 8. Migration Task &    │
                         │    Progress Tracker    │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 9. Crypto-Agility      │
                         │    Analyzer              │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 10. Quantum Readiness  │
                         │     & Compliance View  │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 11. Quantum Security   │
                         │     Assistant           │
                         └────────────┬───────────┘
                                      ↓
                         ┌────────────────────────┐
                         │ 12. Reports & Executive│
                         │     Dashboard           │
                         └────────────────────────┘
```

Not every module has to be built at once. The modules should be implemented in stages.

---

# 3. Module 1 — Asset Discovery & Automated Ingestion

## What is the purpose?

Before an organization can migrate its cryptography, it first needs to know:

> **Where is cryptography being used?**

A real organization may have:

- TLS certificates
- Web servers
- APIs
- Databases
- VPN systems
- Applications
- Digital signatures
- Key-exchange mechanisms
- Configuration files
- Cloud services

Manually entering every asset is not practical.

Therefore, this module allows users to **upload or provide cryptographic information automatically**.

---

## What can the user provide?

Start with a small number of practical inputs:

```text
1. Manual asset entry
2. CSV upload
3. Certificate upload (.crt / .pem)
4. Later: selected configuration files
```

Do not try to support every possible enterprise system initially.

---

## Example

Suppose a company uploads:

```text
website_certificate.pem
```

The platform reads the certificate and extracts information such as:

```text
Subject: example.com
Issuer: Example CA
Public Key Algorithm: RSA
Key Size: 2048
Signature Algorithm: SHA256-RSA
Expiry Date: 2027-05-10
```

The system then converts this information into its internal asset format:

```json
{
  "asset_name": "example.com",
  "asset_type": "TLS Certificate",
  "algorithm": "RSA",
  "key_size": 2048,
  "signature_algorithm": "SHA256-RSA"
}
```

This information can then be sent to the risk assessment system.

---

## How will it be implemented?

Possible backend:

```text
FastAPI
```

Useful Python libraries:

```text
cryptography
pandas
```

Flow:

```text
User uploads certificate
        ↓
FastAPI upload endpoint
        ↓
Certificate parser
        ↓
Extract cryptographic information
        ↓
Convert to common asset format
        ↓
Store in database
        ↓
Send to assessment pipeline
```

---

## Important design decision

Every input method should eventually produce the **same internal asset structure**.

For example:

```text
CSV
Manual Entry
Certificate
Configuration File
       ↓
Common Asset Object
       ↓
Database
       ↓
All other modules
```

This makes the rest of the system much easier to develop.

---

# 4. Module 2 — Cryptographic Inventory

## What is the purpose?

After discovering assets, the platform needs a central place to keep track of them.

This is the **Cryptographic Inventory**.

Think of it as:

> **A database of all cryptographic assets used by the organization.**

---

## Example inventory

| Asset | Type | Algorithm | Key Size | Risk |
|---|---|---|---:|---|
| Website | TLS | RSA | 2048 | High |
| Customer DB | Encryption | AES | 256 | Medium |
| VPN | Key Exchange | ECC | 256 | Critical |
| Internal App | Certificate | RSA | 4096 | Medium |

The user should be able to search and filter this inventory.

For example:

```text
Show all RSA assets
```

or:

```text
Show all Critical assets
```

or:

```text
Show all certificates expiring soon
```

---

## Why is this important?

Without an inventory, the organization does not know:

- How many cryptographic assets it has
- Which algorithms are being used
- Where RSA/ECC are being used
- Which systems are vulnerable
- Which systems need migration

So this module answers:

> **"What cryptography do we currently have?"**

---

# 5. Module 3 — Quantum Risk Assessment

## What is the purpose?

This is the main **Phase 1 ML component** of the project.

The system takes information about an asset and predicts its quantum security risk.

For example:

```text
Asset:
Customer Database

Current Algorithm:
RSA-2048

Data Sensitivity:
High

System Criticality:
High
```

The model produces:

```text
Quantum Risk Score: 85 / 100

Risk Category: Critical
```

---

## Your Phase 1

Your current project already focuses on predictions such as:

```text
Quantum Risk Score
Risk Category
PQC Recommendation
```

However, these outputs should be logically connected.

A cleaner design is:

```text
Input Features
      ↓
Risk Score Model
      ↓
Risk Score
      ↓
Risk Category
```

For example:

```text
0–30   → Low
31–60  → Medium
61–80  → High
81–100 → Critical
```

The exact thresholds should be chosen based on your dataset and project methodology.

---

## PQC recommendation

The PQC recommendation does not necessarily need to be another completely independent ML model.

A better architecture can be:

```text
Risk Prediction
+
Asset Type
+
Current Algorithm
+
Security Requirements
+
Performance Requirements
        ↓
PQC Recommendation Engine
```

This makes the recommendation explainable.

---

## Example

```text
Asset Type:
Key Exchange

Current Algorithm:
ECC

Risk:
Critical

Recommendation:
Consider ML-KEM-based migration/hybrid strategy

Reason:
The asset performs key establishment and has high quantum
exposure.
```

The exact recommendation should follow the cryptographic standards and compatibility assumptions used by your project.

---

# 6. Module 4 — Migration Priority Engine

## What is the purpose?

Risk alone does not tell an organization:

> **Which system should I migrate first?**

Consider two assets:

### Asset A

```text
Quantum Risk = 95
Business Criticality = Low
```

### Asset B

```text
Quantum Risk = 80
Business Criticality = Very High
Sensitive Data = Very High
```

The organization may want to migrate Asset B first.

Therefore, we need a **Migration Priority Score**.

---

## Possible factors

The priority can consider:

```text
Quantum Risk
+
Business Criticality
+
Data Sensitivity
+
Migration Difficulty
+
Exposure
```

For example:

```text
Priority Score =
0.40 × Quantum Risk
+
0.30 × Business Criticality
+
0.20 × Data Sensitivity
+
0.10 × Exposure
```

The weights are only an example and should be validated for the project.

---

## Example

| Asset | Risk | Criticality | Sensitivity | Priority |
|---|---:|---:|---:|---:|
| Payment API | 85 | 100 | 95 | 92 |
| Internal HR Tool | 95 | 30 | 20 | 61 |

The platform can therefore say:

```text
Priority 1 → Payment API
Priority 2 → Customer Database
Priority 3 → VPN
Priority 4 → Internal HR Tool
```

---

## Implementation

This does not need another ML model.

Start with:

```text
Python
+
Weighted scoring
+
Business rules
```

Later, if you obtain enough real-world data, this could be improved.

---

# 7. Module 5 — PQC Recommendation & Migration Strategy Engine

## What is the purpose?

The risk module tells the organization:

> "This asset has a high quantum risk."

But the user then asks:

> **"What should I do about it?"**

This module provides the recommended cryptographic migration strategy.

---

## Example

Input:

```text
Asset:
TLS Server

Current Algorithm:
RSA-2048

Risk:
Critical

Performance Sensitivity:
High
```

Output:

```text
Recommended Strategy:
Evaluate a PQC/hybrid migration approach.

Recommended PQC family:
ML-KEM for key establishment

Priority:
High

Reason:
The system uses quantum-vulnerable public-key cryptography
for key establishment and is highly exposed.
```

For a digital-signature use case, the recommendation could instead involve an appropriate PQC signature algorithm such as ML-DSA.

---

## Why use rules here?

Do not force every part of the system to use ML.

A practical architecture is:

```text
ML
↓
Predict risk

Rule / Decision Engine
↓
Determine appropriate migration strategy
```

This is:

- Easier to explain
- Easier to test
- More transparent
- Easier to modify when standards change

---

# 8. Module 6 — Cost & Performance Impact Analyzer

## What is the purpose?

Organizations do not only ask:

> "Is migration necessary?"

They also ask:

> "How much effort will migration require?"

and:

> "Will the new cryptography affect performance?"

This module gives **estimates**, not guaranteed real-world values.

---

## Example

Current system:

```text
Algorithm: RSA
Estimated latency: 20 ms
```

Proposed migration:

```text
Strategy: PQC / Hybrid
Estimated latency impact: +X%
Estimated compute impact: +Y%
Migration effort: Medium
```

The values can initially be based on assumptions or benchmark data.

---

## Cost estimation

A simple model can be:

```text
Estimated Migration Cost =
Engineer Hours × Hourly Cost
+
Infrastructure Cost
+
Testing Cost
```

Example:

```text
Engineer Hours = 200

Hourly Cost = ₹2,000

Engineering Cost =
200 × ₹2,000
=
₹4,00,000
```

The platform should clearly label this as an **estimate**.

---

## Why is this useful?

The security team can explain migration to management:

```text
"These 12 critical systems need migration."

"Estimated effort is approximately X engineer-hours."

"The highest-priority systems are these five."
```

This turns technical analysis into a business decision.

---

# 9. Module 7 — Migration Roadmap Generator

## What is the purpose?

After the platform identifies what needs to be migrated, it should answer:

> **"What should we do next?"**

The Migration Roadmap Generator converts analysis into a sequence of migration phases.

---

## Example roadmap

### Phase 1 — Discovery

```text
1. Complete cryptographic inventory
2. Identify critical assets
3. Identify legacy algorithms
4. Classify sensitive systems
```

### Phase 2 — Preparation

```text
1. Select pilot application
2. Prepare test environment
3. Review compatibility
4. Establish rollback plan
```

### Phase 3 — Pilot

```text
1. Implement proposed PQC/hybrid configuration
2. Run compatibility tests
3. Measure performance
4. Perform security validation
```

### Phase 4 — High-Priority Migration

```text
1. Migrate critical systems
2. Validate applications
3. Monitor performance
4. Document changes
```

### Phase 5 — Organization-Wide Migration

```text
1. Migrate remaining systems
2. Retire deprecated configurations
3. Verify migration
4. Update inventory
```

---

## How to implement?

Start with a **rule/template-based generator**.

For example:

```python
if risk == "Critical":
    add_task("Immediate migration planning")

if asset_type == "TLS":
    add_task("Evaluate TLS PQC/hybrid compatibility")

if priority_score > 80:
    add_task("Place asset in high-priority migration phase")
```

Later, an LLM can help turn the structured plan into a more readable explanation.

Important:

```text
Rules decide the security action.
LLM explains the action.
```

Do not let an LLM independently invent cryptographic migration decisions.

---

# 10. Module 8 — Migration Task & Progress Tracker

## What is the purpose?

A roadmap is useful, but organizations also need to know:

> **"Have we actually completed the migration?"**

This module converts roadmap recommendations into tasks.

---

## Example

```text
PAYMENT API MIGRATION

[Completed] Asset discovery
[Completed] Risk assessment
[Completed] PQC strategy selected
[In Progress] Test environment
[Pending] Compatibility testing
[Pending] Pilot deployment
[Pending] Production migration
[Pending] Security verification
```

Each task can have:

```text
Task
Priority
Status
Assigned Person
Due Date
Notes
```

---

## Example dashboard

```text
Migration Progress

Completed:    35%
In Progress:  25%
Pending:      40%
```

This changes your system from a:

> **Prediction Dashboard**

into a:

> **Migration Management Platform**

---

# 11. Module 9 — Crypto-Agility Analyzer

## What is crypto-agility?

Crypto-agility means that an application can **change its cryptographic mechanisms without requiring a complete rewrite of the system**.

This becomes important because cryptographic standards can evolve.

---

## Example problem

Suppose an application contains:

```python
algorithm = "RSA"
```

in many different source files.

Changing RSA later could require modifying many files.

This indicates poor crypto-agility.

---

## What your platform can do

Allow the user to upload selected:

```text
Configuration files
JSON
YAML
Selected source files
```

The system scans for:

```text
RSA
ECC
SHA-1
MD5
Hardcoded cryptographic settings
Repeated algorithm configuration
```

Then produce:

```text
Crypto-Agility Score: 45 / 100
```

Example findings:

```text
WARNING:
RSA configuration hardcoded in 5 files.

WARNING:
Legacy SHA-1 usage detected.

GOOD:
Some cryptographic configuration is externalized.
```

---

## Implementation

Start simple:

```text
Regex
+
Pattern Matching
+
Rule-Based Scoring
```

Example:

```python
patterns = {
    "RSA": r"RSA",
    "SHA1": r"SHA-?1",
    "MD5": r"MD5"
}
```

Do not try to build a complete enterprise static-analysis tool.

A basic prototype is enough.

Later, this can be extended using AST-based analysis for supported programming languages.

---

# 12. Module 10 — Quantum Readiness & Compliance View

## What is the purpose?

Risk tells you:

> "How exposed are you?"

Readiness tells you:

> **"How prepared are you for migration?"**

These are different concepts.

---

## Example

```text
Quantum Readiness Score: 72 / 100
```

Possible components:

```text
Crypto Inventory             15 points
Risk Assessment              15 points
Critical Asset Identification 15 points
Migration Plan                15 points
Pilot Testing                 20 points
Migration Progress            20 points
```

Total:

```text
100 points
```

The exact scoring model should be defined by your project.

---

## Dashboard

```text
QUANTUM READINESS

72 / 100
MODERATE

✓ Inventory completed
✓ Risk assessment completed
✓ Critical assets identified
✓ Migration roadmap created
⚠ Pilot migration not completed
⚠ Legacy cryptography remains
```

---

## Compliance wording

Be careful about saying:

> "Your organization is NIST compliant."

Your project should not claim official compliance unless it actually performs a valid compliance assessment.

Prefer:

```text
NIST-alignment checklist
Quantum-readiness assessment
Standards-alignment view
```

This makes the feature more responsible and realistic.

---

# 13. Module 11 — Quantum Security Assistant / Chatbot

## What is the purpose?

The chatbot should not be a generic chatbot.

It should understand the organization's **actual assessment data**.

The user should be able to ask questions such as:

```text
Which asset should I migrate first?

Why is the Payment API critical?

Why was ML-KEM recommended?

Show me all RSA assets.

Explain my migration roadmap.

What are my highest-risk assets?
```

---

## Example

User asks:

> Which system should I migrate first?

The chatbot retrieves the actual assessment data and responds:

```text
The Payment API should be prioritized first.

Reason:
- Quantum Risk Score: 87
- Business Criticality: High
- Data Sensitivity: High
- Migration Priority Score: 93
```

The answer is based on the database, not invented by the chatbot.

---

## Architecture

```text
User
 ↓
Chatbot API
 ↓
Question Understanding
 ↓
Retrieve Relevant Platform Data
 ↓
LLM
 ↓
Answer
```

The assistant can have tools such as:

```text
get_assets()
get_risk_results()
get_priority_assets()
get_pqc_recommendations()
get_migration_tasks()
get_roadmap()
```

---

## Important rule

The chatbot should **not make independent security decisions**.

For example, it should not invent:

```text
"Use Algorithm X because I think it is better."
```

Instead:

```text
Database / Decision Engine
        ↓
Actual recommendation
        ↓
Chatbot explains it
```

This is much safer.

---

# 14. Module 12 — Reports & Executive Dashboard

## What is the purpose?

Different users need different information.

A security engineer wants technical details.

A manager wants a summary.

---

## Security view

Show:

```text
Total Assets
Algorithms
Key Sizes
Risk Levels
Critical Assets
PQC Recommendations
Migration Tasks
Crypto-Agility Findings
```

---

## Executive view

Show:

```text
Overall Quantum Risk
Critical Assets
Migration Progress
Quantum Readiness
Estimated Effort
Top Priorities
```

---

## Example

```text
┌────────────────────────────────────────┐
│       QUANTUM SECURITY OVERVIEW        │
├────────────────────────────────────────┤
│ Quantum Risk             78 / 100      │
│ Risk Category            HIGH           │
│ Critical Assets          12             │
│ Migration Progress       35%            │
│ Quantum Readiness        62 / 100       │
│ Estimated Effort         Medium         │
└────────────────────────────────────────┘
```

---

## PDF report

The platform can generate a report containing:

```text
1. Executive Summary
2. Cryptographic Inventory
3. Quantum Risk Assessment
4. Critical Assets
5. PQC Recommendations
6. Migration Priorities
7. Cost/Effort Estimates
8. Migration Roadmap
9. Crypto-Agility Findings
10. Migration Progress
```

This makes the project useful for demonstrations and presentations.

---

# 15. What NOT to Build

A good project is not one that has the most features.

It is one that has **useful features that can actually be implemented**.

Avoid these for now.

## 15.1 Fully automatic production migration

Do not build:

```text
Upload production infrastructure
        ↓
Automatically change cryptography
        ↓
Automatically deploy to production
```

This is too risky and extremely complex.

Your platform should instead provide:

```text
Assessment
+
Recommendation
+
Planning
+
Configuration Guidance
+
Tracking
```

---

## 15.2 Implementing your own cryptographic algorithms

Do not write your own implementation of:

```text
ML-KEM
ML-DSA
etc.
```

from scratch.

Use established, trusted implementations when cryptographic testing is required.

Your project's main contribution is the **migration intelligence and management layer**, not inventing a new cryptographic primitive.

---

## 15.3 Making everything ML

Do not create an ML model for every feature.

Use the right approach for each problem:

| Problem | Recommended Approach |
|---|---|
| Quantum Risk | ML |
| Risk Category | Derived from Risk Score |
| Migration Priority | Weighted scoring / rules |
| PQC Recommendation | Rule + compatibility engine |
| Roadmap | Rules + templates |
| Cost Estimate | Formula / benchmark |
| Crypto Scan | Regex / static analysis |
| Chatbot | LLM + database/tools |
| Progress Tracking | Database |
| Reports | Backend + templates |

This is a much more realistic architecture.

---

# 16. Recommended Development Order

Do not build all 12 modules simultaneously.

Use this order.

## Phase 1 — Core Intelligence

### Already being developed

```text
1. Dataset Processing
2. Feature Engineering
3. Quantum Risk Score
4. Risk Category
5. PQC Recommendation
6. Results Dashboard
```

Goal:

> Determine the quantum security risk of cryptographic assets.

---

# Phase 2 — Discovery

Build:

```text
1. Manual Asset Entry
2. CSV Upload
3. Certificate Upload
4. Certificate Parser
5. Cryptographic Inventory
```

Flow:

```text
Certificate
     ↓
Parser
     ↓
Crypto Metadata
     ↓
Inventory
     ↓
Risk Assessment
```

This should be your **first major expansion after Phase 1**.

---

# Phase 3 — Decision Intelligence

Build:

```text
1. Migration Priority Score
2. PQC Strategy Engine
3. Cost/Effort Estimator
```

Flow:

```text
Risk Prediction
      +
Business Criticality
      +
Data Sensitivity
      +
Exposure
      ↓
Migration Priority
      ↓
Recommended Strategy
```

This is where the project becomes a real decision-support system.

---

# Phase 4 — Migration Planning

Build:

```text
1. Migration Roadmap
2. Migration Phases
3. Recommended Actions
4. Task Checklist
5. Progress Tracking
```

Flow:

```text
Critical Asset
      ↓
Priority = 95
      ↓
Migration Phase
      ↓
Generate Tasks
      ↓
Track Completion
```

---

# Phase 5 — Security Maturity

Add:

```text
1. Crypto-Agility Analyzer
2. Quantum Readiness Score
3. Standards/Alignment Checklist
4. Legacy Crypto Detection
```

These features make the platform more useful beyond the initial risk prediction.

---

# Phase 6 — AI Assistant & Reporting

Finally add:

```text
1. Organization-aware chatbot
2. Natural-language querying
3. Executive dashboard
4. PDF reports
```

Example:

```text
User:
"Which assets are most urgent?"

        ↓

Chatbot retrieves:
Risk + Priority + Criticality

        ↓

Answer:
"These five assets have the highest migration priority."
```

---

# 17. Final Recommended Project Architecture

The strongest practical version of your project would look like this:

```text
                 ┌──────────────────────────┐
                 │       USER / ADMIN       │
                 └────────────┬─────────────┘
                              ↓
                 ┌──────────────────────────┐
                 │  ASSET DISCOVERY         │
                 │  CSV / Certificate /     │
                 │  Manual Input            │
                 └────────────┬─────────────┘
                              ↓
                 ┌──────────────────────────┐
                 │ CRYPTOGRAPHIC INVENTORY  │
                 └────────────┬─────────────┘
                              ↓
                 ┌──────────────────────────┐
                 │ QUANTUM RISK ENGINE      │
                 │        ML MODELS         │
                 └────────────┬─────────────┘
                              ↓
                 ┌──────────────────────────┐
                 │ MIGRATION PRIORITY       │
                 │ ENGINE                   │
                 └────────────┬─────────────┘
                              ↓
                 ┌──────────────────────────┐
                 │ PQC RECOMMENDATION &     │
                 │ STRATEGY ENGINE          │
                 └────────────┬─────────────┘
                              ↓
                 ┌──────────────────────────┐
                 │ COST & PERFORMANCE       │
                 │ ESTIMATOR                │
                 └────────────┬─────────────┘
                              ↓
                 ┌──────────────────────────┐
                 │ MIGRATION ROADMAP        │
                 │ GENERATOR                │
                 └────────────┬─────────────┘
                              ↓
                 ┌──────────────────────────┐
                 │ TASK & PROGRESS TRACKER  │
                 └────────────┬─────────────┘
                              ↓
          ┌───────────────────┴───────────────────┐
          ↓                                       ↓
┌──────────────────────┐              ┌──────────────────────┐
│ CRYPTO-AGILITY       │              │ QUANTUM READINESS    │
│ ANALYZER             │              │ & ALIGNMENT          │
└──────────────────────┘              └──────────────────────┘
          │                                       │
          └───────────────────┬───────────────────┘
                              ↓
                 ┌──────────────────────────┐
                 │ AI SECURITY ASSISTANT    │
                 │ + REPORTING             │
                 └──────────────────────────┘
```

---

# 18. The Core Idea to Remember

The easiest way to understand the whole project is:

```text
DISCOVER
"What cryptography do we have?"
        ↓
ASSESS
"How vulnerable are we?"
        ↓
PRIORITIZE
"What should we migrate first?"
        ↓
RECOMMEND
"What PQC strategy should we consider?"
        ↓
ESTIMATE
"What effort/performance impact can we expect?"
        ↓
PLAN
"What steps should we follow?"
        ↓
EXECUTE & TRACK
"Which migration tasks are completed?"
        ↓
VERIFY
"How quantum-ready are we now?"
        ↓
ASSIST
"Can I ask the platform questions about my organization?"
```

This gives every module a clear purpose.

The project therefore evolves from:

```text
             PHASE 1
       ML Prediction System
              ↓
"How much quantum risk do I have?"
```

into:

```text
             PHASE 2
   Quantum-Safe Migration Platform
              ↓
"What do I have?"
"What is at risk?"
"What should I migrate first?"
"What should I use?"
"How much effort will it take?"
"What should I do?"
"How do I track it?"
"How ready am I?"
"Can I ask questions about it?"
```

That is the version that is much more likely to feel like a **real-world product rather than only an ML project**.


![Uploading image.png…]()

