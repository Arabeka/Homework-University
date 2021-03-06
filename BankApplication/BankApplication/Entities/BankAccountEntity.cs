using BankApplication.Entities.Base;
using BankApplication.Enumerations;
using System.Collections.Generic;

namespace BankApplication.Entities {

    public class BankAccountEntity : IBaseEntity {

        public int Id { get; set; }
        public int UserId { get; set; }
        public Currency Currency { get; set; }
        public decimal MoneyCount { get; set; }
        public bool IsFrozen { get; set; }

        public UserEntity User { get; set; }
        public List<CreditCardEntity> CreditCards { get; set; }
        public List<UserCreditEntity> UserCredits { get; set; }
        public List<UserDepositEntity> UserDeposits { get; set; }

        public override string ToString() {
            return Currency.ToString() + " " + MoneyCount +  (IsFrozen ? " Frozen" : " Not Frozen");
        }
    }
}
